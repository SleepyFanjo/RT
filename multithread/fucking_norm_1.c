/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fucking_norm_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 10:34:29 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 10:43:30 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "multithread.h"

t_list	*get_thread_lst(t_limit *limit, t_param *p, int id)
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

int		ft_min(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

int		ft_max(int nb1, int nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}

t_list	*get_lst_thread(t_param *p, int *i_e, int step)
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
