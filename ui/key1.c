/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 15:49:35 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 09:45:10 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "ui.h"

int		render(int keycode, t_param *param)
{
	if (keycode != 114)
		return (0);
	R = 1;
	return (1);
}

int		live(int keycode, t_param *param)
{
	if (keycode != 108)
		return (0);
	if (L)
		L = 0;
	else
		L = 1;
	return (1);
}

int		save(t_param *param)
{
	char		*name;
	int			fd;

	name = "save";
	if ((fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
		exit (0);
	put_cam(param, fd);
	put_sphere(param, fd);
	put_spot(param, fd);
	put_plane(param, fd);
	put_cone(param, fd);
	put_cylinder(param, fd);
	close(fd);
	return (1);
}

int		how_high(int keycode, t_param *param)
{
	if (keycode == PLUS)
	{
		POS->y += 25;
		return (1);
	}
	if (keycode == MINUS)
	{
		POS->y -= 25;
		return (1);
	}
	return (0);
}

int		back_to_cam(int keycode, t_param *param)
{
	if (keycode != 118)
		return (0);
	POS = &(param->cam);
	ROT = &(param->rot_cam);
	RADIUS = NULL;
	return (1);
}
