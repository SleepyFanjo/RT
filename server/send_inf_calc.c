#include "../includes/network.h"

int		send_inf_calc(t_list *list, t_info_serv *inf, int nb_cl)
{
	t_inf_exec	*exec;
	t_client	*cl;

	ft_printf("send core\n");
	exec = malloc(sizeof(t_inf_exec));
	exec->nb_tot_th = nb_cl * inf->nb_th;
	exec->nb_st_th = 0;
	exec->nb_th = inf->nb_th;
	while (list != NULL)
	{
		cl = (t_client *)list->content;
		write(cl->sockfd, exec, sizeof(t_inf_exec));
		printf("nb_cl: %d, st_th: %d\n", nb_cl, exec->nb_st_th);
		exec->nb_st_th += exec->nb_th;
		list = list->next;
	}
	if ((list != NULL) ^ (exec->nb_st_th < exec->nb_tot_th))
		ft_printf("%r#11\n");
	free(exec);
	return (0);
}
