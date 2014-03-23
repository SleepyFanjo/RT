#include "network.h"

int		main(int argc, char **argv)
{
	t_info_serv		*inf;
	t_list			*lst_id_cl;
	t_list			*lst_th;
	int				nb_cl;

	inf = malloc(sizeof(t_info_serv));
	lst_id_cl = NULL;
	lst_th = NULL;
	if (argc != 4)
	{
		ft_printf("%rBad usage: ./RT scene.rt list.host nb_thread\n");
		return (1);
	}
	if ((inf->stage = get_stage(argv[1])) == NULL)
		return (1);
	if ((inf->name_serv = getenv("HOST")) == NULL)
	{
		ft_printf("HOST var not defined\n");
		return (1);
	}
	inf->nb_th = ft_atoi(argv[3]);
	inf->size_img[0] = WIDTH;
	inf->size_img[1] = HEIGHT;
	get_lst_cl(argv[2], &lst_id_cl);
	nb_cl = get_cl_th(&lst_th, lst_id_cl, inf);
	send_stage(inf, lst_th);
	send_inf_calc(lst_th, inf, nb_cl);
	get_cl_stage(lst_th);
	return (0);
}
