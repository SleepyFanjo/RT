/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 15:49:38 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/21 17:37:33 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "ui.h"

#include <stdio.h>

int		zoom(int keycode, t_param *param)
{
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

int		wasd(int keycode, t_param *param)
{
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

int		arrows(int keycode, t_param *param)
{
	double		*tmp;

	if (keycode == UP)
	{
		tmp = &CR_X;
		*tmp -= 2;
		return (1);
	}
	if (keycode == DOWN)
	{
		tmp = &CR_X;
		*tmp += 2;
		return (1);
	}
	if (keycode == RIGHT)
	{
		tmp = &CR_Y;
		*tmp += 2;
		return (1);
	}
	if (keycode == LEFT)
	{
		tmp = &CR_Y;
		*tmp -= 2;
		return (1);
	}
	return (0);
}
