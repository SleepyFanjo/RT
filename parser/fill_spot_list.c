/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_spot_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 14:58:51 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/19 11:08:02 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	get_spot(t_obj *o, char *str)
{
	t_list	*elem;
	t_spot	*obj;
	int		i;
	float	val;

	if ((elem = (t_list *)malloc(sizeof(t_list))) == NULL)
		ft_error("Error : can't malloc", NULL, 1);
	if ((obj = (t_spot *)malloc(sizeof(t_spot))) == NULL)
		ft_error("Error : can't malloc", NULL, 1);
	i = 0;
	obj->coord.x = ft_atoi(str);
	obj->coord.y = ft_atoi(str + next_number(str, &i));
	obj->coord.z = ft_atoi(str + next_number(str, &i));
	val = ft_atoi(str + next_number(str, &i));
	if (val < 0 || val > 1000)
		ft_error("Error : learn to read the rules", NULL, 1);
	obj->value = val / 1000;
	obj->color = get_color(str + next_number(str, &i));
	elem->content = obj;
	elem->next = NULL;
	ft_lstadd(&(o->spot), elem);
}
