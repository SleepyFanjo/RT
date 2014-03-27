/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 15:51:51 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 10:38:32 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "multithread.h"

static int	loop_con_blur(int res, t_thread *cur, t_img *img)
{
	if (cur->limit->e_j > 0)
		res = (cur->limit->e_j - 1) * img->line;
	else
		res = 0;
	res += cur->limit->e_i * (img->bpp / 8);
	return (res);
}

static int	ft_connect_blur(t_list *lst)
{
	t_thread	*prvs;
	t_thread	*cur;
	t_img		*img;
	int			res;

	if (lst == NULL)
		return (0);
	prvs = (t_thread *)lst->content;
	img = &(prvs->p->v_img);
	lst = lst->next;
	while (lst != NULL)
	{
		cur = (t_thread *)lst->content;
		cur->limit->s_j = ft_max(prvs->limit->e_j - 1, 0);
		prvs = (t_thread *)lst->content;
		if (lst->next == NULL)
			return (loop_con_blur(res, cur, img));
		lst = lst->next;
	}
	if (prvs->limit->e_j > 0)
		res = (prvs->limit->e_j - 1) * img->line;
	else
		res = 0;
	res += prvs->limit->e_i * (img->bpp / 8);
	return (res);
}

static void	ft_smooth_lst(t_list *res)
{
	t_thread		*th;
	t_thread		*th_next;

	while (res != NULL)
	{
		if (res->next != NULL)
		{
			th = (t_thread *)(res->content);
			th_next = (t_thread *)(res->next->content);
			th->limit->e_i = th_next->limit->s_i;
			th->limit->e_j = th_next->limit->s_j;
		}
		res = res->next;
	}
}

t_list		*get_thread(t_param *param, t_inf_exec *inf, int *end, int *start)
{
	t_list			*res;
	int				step;
	int				full_size;
	int				i_e[2];

	if (inf->nb_th < 1)
	{
		ft_printf("%rNumber of thread is too small (min 1) (%d)\n", inf->nb_th);
		exit(1);
	}
	full_size = WIDTH * HEIGHT;
	step = full_size / inf->nb_tot_th;
	step++;
	i_e[0] = inf->nb_st_th * step;
	*start = i_e[0] * (param->v_img.bpp / 8);
	i_e[1] = ft_min(step * (inf->nb_st_th + inf->nb_th), full_size);
	res = get_lst_thread(param, i_e, step);
	ft_smooth_lst(res);
	*end = ft_connect_blur(res);
	return (res);
}
