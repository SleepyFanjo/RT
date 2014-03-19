/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 15:51:51 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/19 16:46:14 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../multithread.h"

static t_list	*get_thread_lst(t_limit *limit, t_param *p)
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

	th = NULL;
	pos = i_e[0];
	while (pos < i_e[1])
	{
		lim->s_i = pos % WIDTH;
		lim->s_j = pos / WIDTH;
		pos += step;
		lim = (t_limit *)j_malloc(sizeof(t_limit));
		if (pos > i_e[1])
			pos = i_e[1];
		lim->e_i = pos % WIDTH;
		lim->e_j = pos / WIDTH;
		ft_lstadd(&th, get_thread_lst(lim, p));
	}
	return (th);
}

t_list			*get_thread(t_param *param, int nb_t, int nb_t_tot, int nb_t_s)
{
	t_list		*res;
	int			step;
	int			full_size;
	int			i_e[2];

	if (nb_t < 1)
	{
		ft_printf("%rNumber of thread is too small (%d)\n", nb_t);
		exit(1);
	}
	full_size = WIDTH * HEIGHT;
	step = full_size / nb_t_tot;
	step++;
	i_e[0] = nb_t_s * step;
	i_e[1] = step * (nb_t_s + nb_t);
	res = get_lst_thread(param, i_e, step);
	return (res);
}
