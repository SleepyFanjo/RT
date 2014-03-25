#include "../includes/network.h"

void		calc_img(t_list *lst_host, t_info_serv *inf, t_v_env *e)
{
	t_list			*lst_th;
	int				nb_cl;

	lst_th = NULL;
	nb_cl = get_cl_th(&lst_th, lst_host, inf);
	send_env(lst_th, e);
	send_stage(inf, lst_th);
	send_inf_calc(lst_th, inf, nb_cl);
	get_cl_stage(lst_th, e);
}
