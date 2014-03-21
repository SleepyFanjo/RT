#include "../multithread.h"

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
		pthread_join(tmp_cl->th, NULL);
	//	launch_thread((void *)tmp_cl);
		tmp = tmp->next;
	}
	while (th != NULL)
	{
		tmp_cl = (t_thread *)th->content;
	//	pthread_join(tmp_cl->th, NULL);
		th = th->next;
	}
}

void			*print_thread(void *data)
{
	t_thread	*th;
	t_limit		*l;

	th = (t_thread *)data;
	l = th->limit;
	//printf("s_i: %d, s_j: %d, e_i: %d, e_j: %d\n", l->s_i, l->s_j, l->e_i, l->e_j);
	return (data);
}

void			raytracer(t_param *param, int nbr_process)
{
	t_list		*th;
	t_list		*tmp;

	th = get_thread(param, nbr_process, nbr_process, 0);
	tmp = th;
	ft_lstiter(th, print_thread);
	execute_thread(th);
}
