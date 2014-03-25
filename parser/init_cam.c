/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 15:58:58 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/25 19:40:30 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <fcntl.h>

static t_coord	get_rot(char *str, int i)
{
	t_coord		rot;

	rot.x = ft_atoi(str + next_number(str, &i));
	rot.y = ft_atoi(str + next_number(str, &i));
	rot.z = ft_atoi(str + next_number(str, &i));
	return (rot);
}

/*t_coord			init_cam(t_coord *rot, char *dir)
{
	t_coord		cam;
	int			fd;
	int			i;
	char		*line;
	char		*file;

	file = ft_strjoin(dir, "/cam.rt");
	if ((fd = open(file, O_RDONLY)) < 1)
		ft_error("Error : can't init cam, file not found", NULL, 1);
	i = 0;
		if (line[0] != '#')
		{
			cam.x = ft_atoi(line);
			cam.y = ft_atoi(line + next_number(line, &i));
			cam.z = ft_atoi(line + next_number(line, &i));
			*rot = get_rot(line, i);
		}
		free(line);
	free(file);
	if (i == 0)
		ft_error("Error : can't init cam, incorrect file", NULL, 1);
	return (cam);
}*/
