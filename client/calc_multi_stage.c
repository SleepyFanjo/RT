#include "../includes/client.h"

void		calc_multi_stage(int socketfd, t_inf_exec *inf)
{
	t_param	*param;

	param = j_malloc(sizeof(t_param));
	init_param(param, NAME_STAGE);
	raytracer(param, inf);
	expose_hook(param);
	ft_printf("is fucking here\n");
	mlx_expose_hook(param->env.win, expose_hook, &param);
	ft_printf("and now here\n");
	mlx_key_hook(param->env.win, key_hook, &param);
	ft_printf("next\n");
	sleep(3);
	mlx_loop(param->env.mlx);
	(void)socketfd;
}
