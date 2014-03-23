#include "../includes/client.h"

void		calc_multi_stage(int socketfd, t_inf_exec *inf, t_img *img)
{
	t_param	*param;

	param = j_malloc(sizeof(t_param));
	ft_printf("start\n");
	param->v_img = *img;
	init_param(param, NAME_STAGE);
	ft_printf("next\n");
	ft_printf("parser\n");
	parser(NAME_STAGE, param);
	ft_printf("raytracer\n");
	raytracer(param, inf, socketfd);
//	expose_hook(param);
//	mlx_expose_hook(param->env.win, expose_hook, &param);
//	mlx_key_hook(param->env.win, key_hook, &param);
//	mlx_loop(param->env.mlx);
}
