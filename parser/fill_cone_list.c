/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cone_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:46:55 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/19 11:08:45 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	get_cone(t_obj *o, char *str)
{
	t_list		*elem;
	t_cone		*obj;
	int			i;

	if ((elem = (t_list *)malloc(sizeof(t_list))) == NULL)
		ft_error("Error : can't malloc", NULL, 1);
	if ((obj = (t_cone *)malloc(sizeof(t_cone))) == NULL)
		ft_error("Error : can't malloc", NULL, 1);
	i = 0;
	obj->rot.x = ft_atoi(str + first_number(str, &i));
	obj->rot.y = ft_atoi(str + next_number(str, &i));
	obj->rot.z = ft_atoi(str + next_number(str, &i));
	obj->pos.x = ft_atoi(str + next_number(str, &i));
	obj->pos.y = ft_atoi(str + next_number(str, &i));
	obj->pos.z = ft_atoi(str + next_number(str, &i));
	obj->alpha = ft_atoi(str + next_number(str, &i));
	obj->color = get_color(str + next_number(str, &i));
	elem->content = obj;
	elem->next = NULL;
	ft_lstadd(&(o->cone), elem);
}
