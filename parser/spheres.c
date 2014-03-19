/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 11:06:20 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/19 10:47:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static void	add_limit(t_sphere *obj, char *str, int *i)
{
	obj->lim_h_x = ft_atoi(str + next_number(str, i));
	obj->lim_b_x = ft_atoi(str + next_number(str, i));
	obj->lim_h_y = ft_atoi(str + next_number(str, i));
	obj->lim_b_y = ft_atoi(str + next_number(str, i));
	obj->lim_h_z = ft_atoi(str + next_number(str, i));
	obj->lim_b_z = ft_atoi(str + next_number(str, i));
}

int			first_number(char *str, int *i)
{
	while (str[*i] != '-' && !ft_isdigit(str[*i]))
	{
		if (str[*i] == '\0')
			ft_error("Error : file incorrect, incomplete line", NULL, 1);
		*i = *i + 1;
	}
	return (*i);
}

int			next_number(char *line, int *i)
{
	while (line[*i] != ' ' && line[*i] != '\0')
		*i = *i + 1;
	while (line[*i] == ' ')
	{
		*i = *i + 1;
	}
	return (*i);
}

t_list		*get_sphere(char *str)
{
	t_list		*elem;
	int			i;
	t_sphere	*obj;

	if (str[0] == '#')
		return (NULL);
	if ((elem = (t_list *)malloc(sizeof(t_list))) == NULL)
		ft_error("Error, can't malloc", NULL, 1);
	if ((obj = (t_sphere *)malloc(sizeof(t_sphere))) == NULL)
		ft_error("Error, can't malloc", NULL, 1);
	i = 0;
	obj->pos.x = ft_atoi(str + first_number(str, &i));
	obj->pos.y = ft_atoi(str + next_number(str, &i));
	obj->pos.z = ft_atoi(str + next_number(str, &i));
	obj->radius = ft_atoi(str + next_number(str, &i));
	obj->color = get_color(str + next_number(str, &i));
	add_limit(obj, str, &i);
	elem->content = obj;
	elem->next = NULL;
	return (elem);
}
