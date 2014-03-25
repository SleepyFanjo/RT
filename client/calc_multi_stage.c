#include "../includes/client.h"

void	calc_multi_stage(int sockfd, t_inf_exec *inf, t_img *img, t_textures *t)
{
	t_param		*param;

	param = j_malloc(sizeof(t_param));
	param->v_img = *img;
	param->text = t;
	ft_printf("is here\n");
	init_param(param, NAME_STAGE);
	ft_printf("is after\n");
	parser(NAME_STAGE, param);
	raytracer(param, inf, sockfd);
}
