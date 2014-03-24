/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 16:27:09 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/24 20:43:30 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <fcntl.h>

t_env			get_env(void)
{
	t_env		env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, "Fuckin' Raytrcer");
	env.img = mlx_new_image(env.mlx, WIDTH, HEIGHT);
	//env.ui = mlx_xpm_file_to_image(env.mlx, "ui/ui.xpm", &x, &y);
	if (env.mlx == NULL || env.win == NULL || env.img == NULL)
		ft_error("Error : can't init mlx", NULL, 1);
	return (env);
}

void			init_param(t_param *param, char *dir)
{
	t_img		*img;

	parser(dir, param);
	param->env = get_env();
	img = &(param->v_img);
	img->addr = mlx_get_data_addr(param->env.img, &(img->bpp), &(img->line),
			&(img->endian));
	init_ui(param);
	get_textures(param, param->env);
}
