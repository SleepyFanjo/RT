/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_spot_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 14:58:51 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/19 11:09:54 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <fcntl.h>

static t_list	*get_spot(char *str)
{
	t_list	*elem;
	t_spot	*obj;
	int		i;
	float	val;

	if (str[0] == '#')
		return (NULL);
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
	obj->color = get_color(ft_atoi(str + next_number(str, &i)));
	elem->content = obj;
	elem->next = NULL;
	return (elem);
}

t_list			*fill_spot_list(char *dir)
{
	t_list	*list;
	char	*line;
	char	*file;
	int		fd;

	list = NULL;
	file = ft_strjoin(dir, "/spot.rt");
	if ((fd = open(file, O_RDONLY)) < 1)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		add_in_list(&list, get_spot(line));
		free(line);
	}
	free(file);
	return (list);
}
