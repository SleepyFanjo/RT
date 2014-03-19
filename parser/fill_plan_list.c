/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_plan_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:46:55 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/19 10:45:44 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <fcntl.h>

static t_list	*get_plane(char *str)
{
	t_list		*elem;
	t_plane		*obj;
	int			i;

	if (str[0] == '#')
		return (NULL);
	if ((elem = (t_list *)malloc(sizeof(t_list))) == NULL)
		ft_error("Error : can't malloc", NULL, 1);
	if ((obj = (t_plane *)malloc(sizeof(t_plane))) == NULL)
		ft_error("Error : can't malloc", NULL, 1);
	i = 0;
	obj->vec.x = ft_atoi(str + first_number(str, &i));
	obj->vec.y = ft_atoi(str + next_number(str, &i));
	obj->vec.z = ft_atoi(str + next_number(str, &i));
	obj->d = -obj->vec.x * ft_atoi(str + next_number(str, &i));
	obj->d = obj->d - (obj->vec.y * ft_atoi(str + next_number(str, &i)));
	obj->d = obj->d - (obj->vec.z * ft_atoi(str + next_number(str, &i)));
	obj->color = get_color(ft_atoi(str + next_number(str, &i)));
	elem->content = obj;
	elem->next = NULL;
	return (elem);
}

t_list			*fill_plane_list(char *dir)
{
	t_list		*list;
	char		*line;
	char		*file;
	int			fd;

	list = NULL;
	file = ft_strjoin(dir, "/plane.rt");
	if ((fd = open(file, O_RDONLY)) < 1)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		add_in_list(&list, get_plane(line));
		free(line);
	}
	free(file);
	return (list);
}
