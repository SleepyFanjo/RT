/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cone_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:46:55 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/19 10:26:09 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <fcntl.h>

static t_list	*get_cone(char *str)
{
	t_list		*elem;
	t_cone		*obj;
	int			i;

	if (str[0] == '#')
		return (NULL);
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
	return (elem);
}

t_list			*fill_cone_list(char *dir)
{
	t_list		*list;
	char		*line;
	char		*file;
	int			fd;

	list = NULL;
	file = ft_strjoin(dir, "/cone.rt");
	if ((fd = open(file, O_RDONLY)) < 1)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		add_in_list(&list, get_cone(line));
		free(line);
	}
	free(file);
	return (list);
}
