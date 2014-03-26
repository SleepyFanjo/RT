/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 15:30:47 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/26 15:18:25 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	del_list(t_list *list)
{
	t_list	*next;

	while (list != NULL)
	{
		next = list->next;
		free(list);
		list = next;
	}
}

void		ft_lstdel(t_list **begin, t_list *elem)
{
	t_list		*cur;

	if (elem == NULL || *begin == NULL)
		return ;
	cur = *begin;
	if (cur == elem)
	{
		*begin = NULL;
		del_list(elem);
		return ;
	}
}
