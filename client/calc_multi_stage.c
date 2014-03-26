#include "../includes/client.h"

void	calc_multi_stage(int sockfd, t_inf_env *inf_env)
{
	t_param		*param;

	param = j_malloc(sizeof(t_param));
	param->v_img = *(inf_env->img);
	init_param(param, NAME_STAGE);
	parser(NAME_STAGE, param);
	param->text = inf_env->t;
	param->t = inf_env->event;
	raytracer(param, inf_env->inf, sockfd);
}
