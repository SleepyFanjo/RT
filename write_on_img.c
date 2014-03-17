/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_on_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 14:42:34 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/17 14:48:12 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void		write_on_img(t_param *param, int color, int i, int j)
{
	unsigned int	value;
	t_img			img;

	value = mlx_get_color_value(param->env.mlx, color);
	if (value != 0 && LOADING)
		mlx_pixel_put(param->env.mlx, param->env.win, j, i, value);
	PIX = mlx_get_data_addr(param->env.img, &BPP, &LINE, &ENDIAN);
	BPP = BPP / 8;
	PIX = PIX + BPP * j + LINE * i;
	ft_memcpy(PIX, &value, BPP);
}
