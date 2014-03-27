/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 12:03:38 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 16:11:24 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/network.h"
#include "../includes/ui.h"

int			mouse_hook(int button, int x, int y, t_v_env *e)
{
	t_info		*info;
	t_param		*param;
	static void	(*obj_tab[4])(t_param *, t_info *) =

	{&clic_sphere, &clic_plane, &clic_cylinder, &clic_cone};
	param = e->p;
	(void)button;
	calc_matrix((void *)param, CAM);
	info = init_info(param, y, x);
	calc_intersection(param, info);
	FOCUS = info->obj_type;
	if (FOCUS == -1)
	{
		free(info);
		return (0);
	}
	obj_tab[FOCUS](param, info);
	free(info);
	return (0);
}

int			expose_hook(void *env)
{
	t_v_env		*e;

	e = (t_v_env *)env;
	if (e->img == NULL)
		return (0);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

static void	norminette_mary_me(t_param *param, t_v_env *e, int i)
{
	if (i != 10)
	{
		save(param);
		if ((e->inf->stage = get_stage("save")) == NULL)
			exit (0);
		calc_img(e->lst_id_cl, e->inf, e);
		expose_hook(e);
	}
}

int			key_hook(int keycode, t_v_env *e)
{
	int			i;
	t_param		*param;
	static int	(*key_tab[10])(int, t_param *) =

	{&arrows, &how_high, &wasd, &render, &live, &back_to_cam, &roll
	, &rad, &del, &copy};
	param = e->p;
	i = 0;
	if (keycode == 65307)
		exit(0);
	R = 0;
	while (i != 10)
	{
		if (key_tab[i](keycode, param))
			break ;
		i++;
	}
	norminette_mary_me(param, e, i);
	return (0);
}
