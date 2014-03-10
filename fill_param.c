/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 18:55:26 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/10 19:00:50 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static t_env	get_env(void)
{
	t_env	env;

	if ((env.mlx = mlx_init()) == NULL)
		ft_error("Error : can't init mlx", NULL, 1);
	env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, "Raytracer");
	if (env.win == NULL);
		ft_error("Error : can't open window");
	if ((env.img = mlx_new_image(env.mlx, WIDTH, HEIGHT)) == NULL)
		ft_error("Error : can't create image");
	return (env);
}

void			fill_param(t_param *param, char *str)
{
	param->env = get_env();
	parser(str, param);
}
