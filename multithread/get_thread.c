/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 15:51:51 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/18 12:04:13 by qchevrin         ###   ########.fr       */
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

static void		add_thread_lst(t_list **lst, int step, int *i_e, t_param *p)
{
	t_limit		*limit;

	if ((limit = (t_limit *)malloc(sizeof(t_limit))) == NULL)
	{
		ft_printf("%rMalloc Fail\n");
		exit(1);
	}
	limit->s_i = i_e[0] % W;
	limit->s_j = i_e [0] / W;
	i_e[0] += step;
	if (i_e[0] > end)
	{
		limit->e_i = i_e[1]% W;
		limit->e_j = i_e[1] / W;
	}
	else
	{
		limit->e_i = i_e[0] % W;
		limit->e_j = i_e[0] / W;
	}
	ft_lstadd(lst, get_thread_lst(limit, p));
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
	res = NULL;
	full_size = WIDTH * HEIGHT;
	step = full_size / nb_t_tot;
	step += 1;
	i_e[0] = nb_t_s * step;
	i_e[1] = step * (nb_t_s + nb_t);
	while (index < end)
		add_thread_lst(&res, step, index, end);
	(void)param;
	return (res);
}
