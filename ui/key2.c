/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 09:36:00 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 10:00:37 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "ui.h"

int				roll(int keycode, t_param *param)
{
	if (keycode == NINE)
	{
		ROT->z += 5;
		if (ROT->z < 0)
			ROT->z += 360;
		if (ROT->z > 360)
			ROT->z -= 360;
		return (1);
	}
	if (keycode == SIX)
	{
		ROT->z -= 5;
		if (ROT->z < 0)
			ROT->z += 360;
		if (ROT->z > 360)
			ROT->z -= 360;
		return (1);
	}
	return (0);
}

int				wasd(int keycode, t_param *param)
{
	if (keycode == W)
	{
		POS->z += 25;
		return (1);
	}
	if (keycode == S)
	{
		POS->z -= 25;
		return (1);
	}
	if (keycode == D)
	{
		POS->x += 25;
		return (1);
	}
	if (keycode == A)
	{
		POS->x -= 25;
		return (1);
	}
	return (0);
}

static int		arrows_bis(int keycode, t_param *param)
{
	if (keycode == RIGHT)
	{
		ROT->y -= 5;
		if (ROT->y < 0)
			ROT->y += 360;
		if (ROT->y > 360)
			ROT->y -= 360;
		return (1);
	}
	if (keycode == LEFT)
	{
		ROT->y += 5;
		if (ROT->y < 0)
			ROT->y += 360;
		if (ROT->y > 360)
			ROT->y -= 360;
		return (1);
	}
	return (0);
}

int				arrows(int keycode, t_param *param)
{
	if (keycode == UP)
	{
		ROT->x -= 5;
		if (ROT->x < 0)
			ROT->x += 360;
		if (ROT->x > 360)
			ROT->x -= 360;
		return (1);
	}
	if (keycode == DOWN)
	{
		ROT->x += 5;
		if (ROT->x < 0)
			ROT->x += 360;
		if (ROT->x > 360)
			ROT->x -= 360;
		return (1);
	}
	return (arrows_bis(keycode, param));
}
