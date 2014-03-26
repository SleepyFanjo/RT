#include "multithread.h"
#include "../includes/client.h"

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

int		raytracer(t_param *param, t_inf_exec *inf, int sockfd)
{
	t_list		*th;
	t_list		*tmp;
	int			end;
	int			start;
	int			tmp_ret;

	th = get_thread(param, inf, &end, &start);
	send_message(sockfd, sizeof(int), &start);
	send_message(sockfd, sizeof(int), &end);
	if (get_value(sockfd, &tmp_ret, sizeof(int)) < 0 || tmp_ret != SIZE_SUCCES)
	{
		ft_printf("%r#12\n");
		exit(12);
	}
	tmp = th;
	execute_thread(th);
	send_stage(sockfd, param, start, end);
	if (get_value(sockfd, &tmp_ret, sizeof(int)) < 0 || tmp_ret != STAGE_SUCCES)
	{
		ft_printf("%r#13\n");
		exit(12);
	}
//	free_obj_lst(param);
	return (0);
}
