/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 16:27:09 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/21 15:17:53 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <fcntl.h>

t_env			get_env(void)
{
	t_env		env;
	int			x;
	int			y;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT + H_UI, "RtV1");
	env.img = mlx_new_image(env.mlx, WIDTH, HEIGHT);
	env.ui = mlx_xpm_file_to_image(env.mlx, "ui/ui.xpm", &x, &y);
	if (env.mlx == NULL || env.win == NULL || env.img == NULL)
		ft_error("Error : can't init mlx", NULL, 1);
	return (env);
}

void			init_param(t_param *param, char *dir)
{
	param->env = get_env();
	parser(dir, param);
}
