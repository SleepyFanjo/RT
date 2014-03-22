/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 15:49:38 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/22 16:07:13 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "ui.h"

#include <stdio.h>

int		render(int keycode, t_param *param)
{
	if (keycode != 114)
		return (0);
	R = 1;
	return (1);
}

int		zoom(int keycode, t_param *param)
{
	if (keycode == PLUS)
	{
		C_Y += 25;
		R = 0;
		return (1);
	}
	if (keycode == MINUS)
	{
		C_Y -= 25;
		R = 0;
		return (1);
	}
	return (0);
}

int		wasd(int keycode, t_param *param)
{
	double		*tmp;

	if (keycode == W)
	{
		tmp = &C_Z;
		R = 0;
		*tmp += 25;
		return (1);
	}
	if (keycode == S)
	{
		tmp = &C_Z;
		R = 0;
		*tmp -= 25;
		return (1);
	}
	if (keycode == D)
	{
		R = 0;
		tmp = &C_X;
		*tmp += 25;
		return (1);
	}
	if (keycode == A)
	{
		R = 0;
		tmp = &C_X;
		*tmp -= 25;
		return (1);
	}
	return (0);
}

int		arrows(int keycode, t_param *param)
{
	double		*tmp;

	if (keycode == UP)
	{
		R = 0;
		tmp = &CR_X;
		*tmp -= 2;
		return (1);
	}
	if (keycode == DOWN)
	{
		R = 0;
		tmp = &CR_X;
		*tmp += 2;
		return (1);
	}
	if (keycode == RIGHT)
	{
		R = 0;
		tmp = &CR_Y;
		*tmp += 2;
		return (1);
	}
	if (keycode == LEFT)
	{
		R = 0;
		tmp = &CR_Y;
		*tmp -= 2;
		return (1);
	}
	return (0);
}
