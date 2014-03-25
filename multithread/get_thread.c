/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 15:51:51 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/24 19:13:11 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "multithread.h"

static t_list	*get_thread_lst(t_limit *limit, t_param *p, int id)
{
	t_thread	*th;
	t_list		*res;

	if ((th = (t_thread *)malloc(sizeof(t_thread))) == NULL)
	{
		ft_printf("%rMalloc Fail\n");
		exit(1);
	}
	th->limit = limit;
	th->p = p;
	th->id = id;
	if ((res = ft_lstnew((void *)th, sizeof(t_thread))) == NULL)
	{
		ft_printf("%rMalloc Fail\n");
		exit(1);
	}
	return (res);
}

static t_list	*get_lst_thread(t_param *p, int *i_e, int step)
{
	int		pos;
	t_limit	*lim;
	t_list	*th;
	int		i;

	i = 0;
	th = NULL;
	lim = NULL;
	pos = i_e[0];
	while (pos < i_e[1] - 1)
	{
		lim = (t_limit *)j_malloc(sizeof(t_limit));
		lim->s_i = pos % WIDTH;
		lim->s_j = pos / WIDTH;
		pos += step;
		if (pos >= i_e[1])
			pos = i_e[1] - 1;
		lim->e_i = pos % WIDTH + 1;
		lim->e_j = pos / WIDTH + 1;
		ft_lstadd(&th, get_thread_lst(lim, p, i));
		i++;
	}
	return (th);
}

static int	ft_min(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

static int	ft_max(int nb1, int nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
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
		{
			if (cur->limit->e_j > 0)
				res = (cur->limit->e_j  - 1)* img->line;
			else
				res = 0;
			res += cur->limit->e_i * (img->bpp / 8);
			return (res);
		}
		lst = lst->next;
	}
	if (prvs->limit->e_j > 0)
		res = (prvs->limit->e_j  - 1) * img->line;
	else
		res = 0;
	res += prvs->limit->e_i * (img->bpp / 8);
	return (res);
}

static void		ft_smooth_lst(t_list *res)
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
