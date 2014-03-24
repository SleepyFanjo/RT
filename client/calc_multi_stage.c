#include "../includes/client.h"

void		calc_multi_stage(int socketfd, t_inf_exec *inf, t_img *img)
{
	t_param	*param;

	param = j_malloc(sizeof(t_param));
	param->v_img = *img;
	init_param(param, NAME_STAGE);
	parser(NAME_STAGE, param);
	raytracer(param, inf, socketfd);
}
