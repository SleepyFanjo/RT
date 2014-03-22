#include "../includes/client.h"

void		calc_multi_stage(int socketfd, t_inf_exec *inf)
{
	t_param	*param;

	ft_printf("start\n");
	param = j_malloc(sizeof(t_param));
	ft_printf("next\n");
	init_param(param, NAME_STAGE);
	ft_printf("parser\n");
	parser(NAME_STAGE, param);
	ft_printf("raytracer\n");
	raytracer(param, inf);
	ft_printf("is fucking here\n");
//	expose_hook(param);
//	mlx_expose_hook(param->env.win, expose_hook, &param);
	ft_printf("and now here\n");
//	mlx_key_hook(param->env.win, key_hook, &param);
	ft_printf("next\n");
//	mlx_loop(param->env.mlx);
	ft_printf("after ending absolute\n");
	(void)socketfd;
}
