/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_plan_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:46:55 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/19 11:05:43 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	get_plane(t_obj *o, char *str)
{
	t_list		*elem;
	t_plane		*obj;
	int			i;

	if ((elem = (t_list *)malloc(sizeof(t_list))) == NULL)
		ft_error("Error : can't malloc", NULL, 1);
	if ((obj = (t_plane *)malloc(sizeof(t_plane))) == NULL)
		ft_error("Error : can't malloc", NULL, 1);
	i = 0;
	obj->rot.x = ft_atoi(str + first_number(str, &i));
	obj->rot.y = ft_atoi(str + next_number(str, &i));
	obj->rot.z = ft_atoi(str + next_number(str, &i));
	obj->pos.x = ft_atoi(str + next_number(str, &i));
	obj->pos.y = ft_atoi(str + next_number(str, &i));
	obj->pos.z = ft_atoi(str + next_number(str, &i));
	obj->color = get_color(str + next_number(str, &i));
	elem->content = obj;
	elem->next = NULL;
	ft_lstadd(&(o->plan), elem);
}
