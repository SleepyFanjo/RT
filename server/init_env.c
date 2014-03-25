#include "../includes/network.h"

void		init_env(t_v_env *env)
{
	env->mlx = mlx_init();
	if (env->mlx == NULL)
	{
		ft_printf("%r#6\n");
		exit(6);
	}
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "RayTracer");
	if (env->win == NULL)
	{
		ft_printf("%r#7\n");
		exit(7);
	}
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (env->img == NULL)
	{
		ft_printf("%r#8\n");
		exit(1);
	}
	env->addr = mlx_get_data_addr(env->img, &(env->bpp), &(env->line),
			&(env->endian));
	get_textures(env, env->mlx);
}
