#include "../multithread.h"

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

int			raytracer(t_param *param, int nb_thread)
{
	t_list		*thread;

	thread = get_thread(param, 4, 4, 0);
}
