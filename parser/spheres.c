/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 11:06:20 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/18 18:02:12 by qchevrin         ###   ########.fr       */
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

int			*get_color(int color)
{
	int		*tab;

	tab = (int *)j_malloc(sizeof(int) * 3);
	tab[0] = color % (256);
	color = color / 256;
	tab[1] = color % 256;
	color = color / 256;
	tab[2] = color % 256;
	return (tab);
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
	while (ft_isdigit(line[*i]) || line[*i] == '-')
		*i = *i + 1;
	while (!ft_isdigit(line[*i]) && line[*i] != '-')
	{
		if (line[*i] == '\0')
			ft_error("Error : file incorrect, incomplete line", NULL, 1);
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
	obj->color = get_color(ft_atoi(str + next_number(str, &i)));
	add_limit(obj, str, &i);
	elem->content = obj;
	elem->next = NULL;
	return (elem);
}
