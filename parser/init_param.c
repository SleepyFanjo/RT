/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 16:27:09 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/23 15:04:25 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <fcntl.h>

t_env			get_env(void)
{
	t_env		env;

	env.mlx = mlx_init();
	if (env.mlx == NULL)
	{
		ft_printf("%r#6\n");
		exit(6);
	}
	env.win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "RT");
	if (env->win == NULL)
	{
		ft_printf("%r#7\n");
		exit(7);
	}
	env.img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (env.img == NULL)
	{
		ft_printf("%r#8\n");
		exit(1);
	}
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
	img->addr = j_malloc((img->bpp / 8) * (WIDTH * HEIGHT));
}
