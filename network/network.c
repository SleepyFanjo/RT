#include "../network.h"

int			launch_serv(t_list *lst_cl, int nb_th, int *size_img)
{
	t_list		*lst_thread;

	get_cl_th(&lst_thread, lst_cl, nb_th, size_img);
}
