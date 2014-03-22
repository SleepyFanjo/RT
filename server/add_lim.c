#include "../includes/network.h"

static int				ft_min(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

void		add_lim(t_client *cl, t_inf_exec *exec)
{
	int		full_size;
	int		step;
	int		i_e[2];

	full_size = WIDTH * HEIGHT;
	step = full_size / exec->nb_tot_th;
	step++;
	i_e[0] = exec->nb_st_th * step;
	i_e[1] = ft_min(step * (exec->nb_st_th + exec->nb_th), full_size);
	cl->lim = i_e[0] * 4;
	printf("lim: i: %d, j: %d\n", cl->lim.s_i, cl->lim.s_j);
}
