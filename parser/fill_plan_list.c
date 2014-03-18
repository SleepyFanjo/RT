/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_plan_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:46:55 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/18 14:02:47 by qchevrin         ###   ########.fr       */
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
	obj->rot.x = ft_atoi(str + i);
	obj->rot.y = ft_atoi(str + next_number(str, &i));
	obj->rot.z = ft_atoi(str + next_number(str, &i));
	obj->pos.x = ft_atoi(str + next_number(str, &i));
	obj->pos.y = ft_atoi(str + next_number(str, &i));
	obj->pos.z = ft_atoi(str + next_number(str, &i));
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
