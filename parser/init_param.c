/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 16:27:09 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/19 11:09:45 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <fcntl.h>

t_env			get_env(void)
{
	t_env		env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, "RtV1");
	env.img = mlx_new_image(env.mlx, WIDTH, HEIGHT);
	if (env.mlx == NULL || env.win == NULL || env.img == NULL)
		ft_error("Error : can't init mlx", NULL, 1);
	return (env);
}

void			init_param(t_param *param, char *dir)
{
	param->env = get_env();
	parser(dir, param);
}
