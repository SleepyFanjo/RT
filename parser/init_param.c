/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 16:27:09 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/23 19:36:23 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <fcntl.h>

void			init_param(t_param *param, char *dir)
{
	t_img		*img;

	parser(dir, param);
	img = &(param->v_img);
//	img->addr = mlx_get_data_addr(param->env.img, &(img->bpp), &(img->line),
//			&(img->endian));
	img->addr = j_malloc(img->line * HEIGHT);
}
