#include "multithread.h"

static void	*launch_thread(void *th)
{
	t_thread	*thc;

	thc = (t_thread *)th;
	raythrow(thc);
	return (NULL);
}

static void	execute_thread(t_list *th)
{
	t_list		*tmp;
	t_thread	*tmp_cl;

	tmp = th;
	while (tmp != NULL)
	{
		tmp_cl = (t_thread *)tmp->content;
		pthread_create(&(tmp_cl->th), NULL, launch_thread, (void *)tmp_cl);
		tmp = tmp->next;
	}
	while (th != NULL)
	{
		tmp_cl = (t_thread *)th->content;
		pthread_join(tmp_cl->th, NULL);
		th = th->next;
	}
}

void			raytracer(t_param *param, t_inf_exec *inf)
{
	t_list		*th;
	t_list		*tmp;

	th = get_thread(param, inf->nb_th, inf->nb_tot_th, inf->nb_st_th);
	tmp = th;
	execute_thread(th);
//	free_obj_lst(param);
}
