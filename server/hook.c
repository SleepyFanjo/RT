#include "../includes/network.h"

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
	(void)e;
	if (keycode == 65307)
	{
		ft_printf("Exit\n");
		exit(0);
	}
	return (0);
}
