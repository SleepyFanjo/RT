#include "../includes/network.h"

void		init_env(t_v_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "RT");
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (env->mlx == NULL || env->win == NULL || env->img == NULL)
		ft_error("Error : can't init mlx", NULL, 1);
	env->addr = mlx_get_data_addr(env->img, &(env->bpp), &(env->line),
			&(env->endian));
}
