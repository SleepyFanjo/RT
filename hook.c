/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 13:10:44 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/21 17:35:10 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracer.h"
#include "ui.h"

int		expose_hook(t_param *param)
{
	t_env	env;

	if (param->env.img == NULL)
		return (0);
	env = param->env;
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	mlx_put_image_to_window(env.mlx, env.win, env.ui, 0, HEIGHT);
	return (0);
}

int		key_hook(int keycode, t_param *param)
{
	int			i;
	static int	(*key_tab[3])(int, t_param *) =
				{
					&arrows, &zoom, &wasd
				};

	i = 0;
	if (keycode == 65307)
		exit(0);
	while (i != 3)
	{
		if (key_tab[i](keycode, param))
			break ;
		i++;
	}
	if (i != 3)
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
