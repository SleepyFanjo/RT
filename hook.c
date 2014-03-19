/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 13:10:44 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/17 15:29:21 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int		expose_hook(t_param *param)
{
	t_env	env;

	if (param->env.img == NULL)
		return (0);
	env = param->env;
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	return (0);
}

int		key_hook(int keycode, t_param *param)
{
	(void)param;
	if (keycode == 65307)
		exit(0);
	return (0);
}
