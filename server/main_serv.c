#include "network.h"

static void	ending_mlx(t_v_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	ft_printf("End of compute, press esc to exit\n");
	mlx_loop(e->mlx);
}

static int	get_init_value(int argc, char **argv, t_info_serv *inf)
{

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
	if ((inf->nb_th = ft_atoi(argv[3])) < 1)
	{
		ft_printf("Number of thread is too small (min 1)\n");
		return (1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_info_serv		*inf;
	t_list			*lst_id_cl;
	t_list			*lst_th;
	int				nb_cl;
	t_v_env			*e;

	inf = j_malloc(sizeof(t_info_serv));
	lst_id_cl = NULL;
	lst_th = NULL;
	if (get_init_value(argc, argv, inf))
		return (1);
	get_lst_cl(argv[2], &lst_id_cl);
	nb_cl = get_cl_th(&lst_th, lst_id_cl, inf);
	e = send_env(lst_th);
	send_stage(inf, lst_th);
	send_inf_calc(lst_th, inf, nb_cl);
	get_cl_stage(lst_th, e);
	ending_mlx(e);
	free_cl(lst_th);
	free(inf);
	return (0);
}
