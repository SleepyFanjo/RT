/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_on_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 14:42:34 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/24 14:30:25 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "client.h"

void		write_on_img(t_param *param, int color, int i, int j)
{
	unsigned int	value;
	char			*tmp;
	t_img			*img;

	img = &(param->v_img);
	value = my_mlx_get_color_value(color, img->decrgb, img->depth);
	tmp = img->addr + (img->line * i) + (j * (img->bpp / 8));
	ft_memcpy(tmp, &value, img->bpp / 8);
}
