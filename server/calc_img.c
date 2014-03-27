#include "../includes/network.h"
#include "../includes/ui.h"

static void	*free_th(void *data)
{
	t_client	*cl;

	if (data != NULL)
	{
		cl = (t_client *)data;
		if (cl->name_host_cl != NULL)
			free(cl->name_host_cl);
		free(data);
	}
	return (NULL);
}

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
	ft_lstiter(lst_th, free_th);
	ft_lstdel(&lst_th, lst_th);
}
