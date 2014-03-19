/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 16:27:09 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/18 15:53:55 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <fcntl.h>

void			add_in_list(t_list **list, t_list *elem)
{
	t_list		*cursor;

	if (elem == NULL)
		return ;
	if (*list == NULL)
	{
		*list = elem;
		return ;
	}
	cursor = *list;
	while (cursor->next != NULL)
		cursor = cursor->next;
	cursor->next = elem;
}

static t_list	*fill_sphere_list(char *dir)
{
	t_list		*list;
	char		*line;
	char		*file;
	int			fd;

	list = NULL;
	file = ft_strjoin(dir, "/sphere.rt");
	if ((fd = open(file, O_RDONLY)) < 1)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		add_in_list(&list, get_sphere(line));
		free(line);
	}
	free(file);
	return (list);
}

t_env			get_env(void)
{
	t_env		env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, "RtV1");
	env.img = mlx_new_image(env.mlx, WIDTH, HEIGHT);
	if (env.mlx == NULL || env.win == NULL || env.img == NULL)
		ft_error("Error : can't init mlx", NULL, 1);
	return (env);
}

void			init_param(t_param *param, char *dir)
{
	param->env = get_env();
	param->cam = init_cam(&(param->rot_cam), dir);
	param->spot = fill_spot_list(dir);
	param->sphere = fill_sphere_list(dir);
	param->plane = fill_plane_list(dir);
	param->cylinder = fill_cylinder_list(dir);
	param->cone = fill_cone_list(dir);
}
