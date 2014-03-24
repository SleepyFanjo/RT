/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 13:10:44 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/24 13:07:15 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include "ui.h"

int             mouse_hook(int button, int x, int y, t_param *param)
{
	t_info		info;

	l_printf("button=%d x=%d y=%d\n", button, x, y);
	info = init_info(param, y, x);
	calc_intersection(param, &info);
	FOCUS = info.obj;
	t_sphere *s = FOCUS;
	l_printf("F posx:%d y:%d z:%d", (int)s->pos.x
			, (int)s->pos.y, (int)s->pos.z);
	s->pos.y += 50;
	raytracer(param, 4);
	expose_hook(param);
	return (0);
}

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
	t_coord		*pos;
	t_coord		*rot;
	static int	(*key_tab[6])(int, t_param *, t_coord *, t_coord *) =
	{
		&arrows, &zoom, &wasd, &render, &save, &live
	};

	i = 0;
	pos = NULL;
	rot = NULL;
	if (keycode == 65307)
		exit(0);
	R = 0;
	while (i != 6)
	{

		if (key_tab[i](keycode, param, pos, rot))
			break ;
		i++;
	}
	if (i != 6)
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
