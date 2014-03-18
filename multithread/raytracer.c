#include "../multithread.h"
/*
static void	*launch_thread(void *th)
{
	t_thread	*th;

	th = (t_thread *)th;
	raythrow(th);
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
*/
void			raytracer(t_param *param, int nbr_process)
{
	t_thread		thread;

	(void) nbr_process;
	thread.limit.s_i = 0;
	thread.limit.s_j = 0;
	thread.limit.e_i = HEIGHT;
	thread.limit.e_j = WIDTH;
	thread.p = param;
	raythrow(&thread);
}
