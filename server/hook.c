#include "../includes/network.h"
#include "../includes/ui.h"

int		mouse_hook(int button, int x, int y, t_v_env *e)
{
	t_info		*info;
	t_param		*param;

	param = e->p;
	static void	(*obj_tab[4])(t_param *, t_info *) =
	{
		&clic_sphere, &clic_plane, &clic_cylinder, &clic_cone
	};

	(void)button;
	info = init_info(param, y, x);
	calc_intersection(param, info);
	if (info->obj_type == -1)

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

int		expose_hook(void *env)
{
		t_v_env		*e;

		e = (t_v_env *)env;
		if (e->img == NULL)
			return (0);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		return (0);
}

int		key_hook(int keycode, t_v_env *e)
{
	int			i;
	static int	(*key_tab[6])(int, t_param *) =
	{
		&arrows, &how_high, &wasd, &render, &live, &back_to_cam
	};
	t_param		*param;

	param = e->p;
	i = 0;
	if (keycode == 65307)
		exit(0);
	R = 0;
	while (i != 6)
	{
		if (key_tab[i](keycode, param))
			break ;
		i++;
	}
	if (i != 6)
	{
		save(param);
		if ((e->inf->stage = get_stage("save")) == NULL)
			exit (0);
		calc_img(e->lst_id_cl, e->inf, e);
		expose_hook(e);
	}
	else
	{
		ft_putstr("keycode=");
		ft_putnbr(keycode);
		ft_putstr("\n");
	}
	return (0);
}
