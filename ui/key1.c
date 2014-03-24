/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 15:49:35 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/24 11:54:16 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "ui.h"

#include <stdio.h>

int		render(int keycode, t_param *param, t_coord *pos, t_coord *rot)
{
	(void)pos;
	(void)rot;
	if (keycode != 114)
		return (0);
	R = 1;
	return (1);
}

int		live(int keycode, t_param *param, t_coord *pos, t_coord *rot)
{
	(void)pos;
	(void)rot;
	if (keycode != 108)
		return (0);
	if (L)
		L = 0;
	else
		L = 1;
	return (1);
}

int		save(int keycode, t_param *param, t_coord *pos, t_coord *rot)
{
	(void)pos;
	(void)rot;
	char		*name;
	int			fd;

	if (keycode != 99)
		return (0);
	name = "mabite";
	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	put_cam(param, fd);
	put_sphere(param, fd);
	put_spot(param, fd);
	put_plane(param, fd);
	put_cone(param, fd);
	put_cylinder(param, fd);
	return (1);
}

int		zoom(int keycode, t_param *param, t_coord *pos, t_coord *rot)
{
	(void)pos;
	(void)rot;
	if (keycode == PLUS)
	{
		C_Y += 25;
		return (1);
	}
	if (keycode == MINUS)
	{
		C_Y -= 25;
		return (1);
	}
	return (0);
}

int		wasd(int keycode, t_param *param, t_coord *pos, t_coord *rot)
{
	(void)pos;
	(void)rot;
	double		*tmp;

	if (keycode == W)
	{
		tmp = &C_Z;
		*tmp += 25;
		return (1);
	}
	if (keycode == S)
	{
		tmp = &C_Z;
		*tmp -= 25;
		return (1);
	}
	if (keycode == D)
	{
		tmp = &C_X;
		*tmp += 25;
		return (1);
	}
	if (keycode == A)
	{
		tmp = &C_X;
		*tmp -= 25;
		return (1);
	}
	return (0);
}

int		arrows(int keycode, t_param *param, t_coord *pos, t_coord *rot)
{
	(void)pos;
	(void)rot;
	double		*tmp;

	if (keycode == UP)
	{
		tmp = &CR_X;
		*tmp -= 5;
		return (1);
	}
	if (keycode == DOWN)
	{
		tmp = &CR_X;
		*tmp += 5;
		return (1);
	}
	if (keycode == RIGHT)
	{
		tmp = &CR_Y;
		*tmp += 5;
		return (1);
	}
	if (keycode == LEFT)
	{
		tmp = &CR_Y;
		*tmp -= 5;
		return (1);
	}
	return (0);
}
