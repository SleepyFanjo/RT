/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_on_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 14:42:34 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/22 21:37:18 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void		write_on_img(t_param *param, int color, int i, int j)
{
	static int		test = 1;
	unsigned int	value;
	char			*tmp;
	t_img			*img;

	value = mlx_get_color_value(param->env.mlx, color);
	if (value != 0 && LOADING)
	{
		mlx_pixel_put(param->env.mlx, param->env.win, j, i, value);
		printf("FAIL\n");
	}
	img = &(param->v_img);
	tmp = img->addr + (img->line * i) + (j * (img->bpp / 8));
	if (test)
	{
		ft_printf("start: %d\n", (img->line * i) + (j * (img->bpp / 8)));
		test = 0;
	}
	ft_memcpy(tmp, &value, img->bpp / 8);
}
