/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 13:10:44 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/24 20:43:12 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include "ui.h"

int             mouse_hook(int button, int x, int y, t_param *param)
{
	t_info		*info;
	static void	(*obj_tab[4])(t_param *, t_info *) =
	{
		&clic_sphere, &clic_plane, &clic_cylinder, &clic_cone
	};

	(void)button;
	info = init_info(param, y, x);
	calc_intersection(param, info);
	if (info->obj_type == -1)
	{
		free(info);
		return (0);
	}
	obj_tab[info->obj_type](param, info);
	free(info);
	return (0);
}

int		expose_hook(t_param *param)
{
	t_env	env;

	if (param->env.img == NULL)
		return (0);
	env = param->env;
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	//mlx_put_image_to_window(env.mlx, env.win, env.ui, 0, HEIGHT);
	return (0);
}

int		key_hook(int keycode, t_param *param)
{
	int			i;
	static int	(*key_tab[7])(int, t_param *) =
	{
		&arrows, &how_high, &wasd, &render, &save, &live, &back_to_cam
	};

	i = 0;
	if (keycode == 65307)
		exit(0);
	R = 0;
	while (i != 7)
	{

		if (key_tab[i](keycode, param))
			break ;
		i++;
	}
	if (i != 7)
	{
		raytracer(param, 4);
		expose_hook(param);
	}
	else
	{
		ft_putstr("keycode=");
		ft_putnbr(keycode);
		ft_putstr("\n");
	}
	return (0);
}
