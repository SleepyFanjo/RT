#include "../includes/network.h"

static void	cpy_to_img(int start, char *val, int size, t_v_env *env)
{
	static int		offset;

	if (size == -1)
	{
		offset = start;
		return ;
	}
	ft_memcpy(env->addr + offset, val, size);
	offset += size;
}

static void	get_stage_read(int sockfd, int size, int start, t_v_env *env)
{
	char		*buff;
	int			pos;
	int			ret;
	int			ask_size;
	int			nb_loop;

	buff = malloc(sizeof(char) * (NET_BUFF_SIZE + 10));
	pos = 0;
	cpy_to_img(start, NULL, -1, NULL);
	nb_loop = 0;
	while (pos < size)
	{
		ask_size = size - pos;
		if (ask_size > NET_BUFF_SIZE)
			ask_size = NET_BUFF_SIZE;
		ret = read(sockfd, buff, ask_size);
		if (ret < 0)
		{
			ft_printf("Fail #1\n");
			return ;
		}
		if (ret == 0)
			nb_loop++;
		else
			nb_loop = 0;
		if (nb_loop == LIM_NB_READ)
		{
			ft_printf("%r#15\n");
			return ;
		}
		cpy_to_img(0, buff, ret, env);
		pos += ret;
	}
}

void		get_cl_stage(t_list *lst_th, t_v_env *env)
{
	t_client	*cl;
	int			size_tot;
	int			ret_msg;
	t_list		*tmp;

	tmp = lst_th;
	size_tot = HEIGHT * env->line;
	while (tmp != NULL)
	{
		cl = (t_client *)tmp->content;
		if (get_value(cl->sockfd, (void *)&(cl->start), sizeof(int)) < 0)
		{
			ft_printf("%r#3 cl: %s\n", cl->name_host_cl);
			tmp = tmp->next;
			continue ;
		}
		if (get_value(cl->sockfd, (void *)&(cl->end), sizeof(int)) < 0)
		{
			ft_printf("%r#4 cl: %s\n", cl->name_host_cl);
			tmp = tmp->next;
			continue ;
		}
		ret_msg = SIZE_SUCCES;
		send_message(cl->sockfd, sizeof(int), &ret_msg);
		tmp = tmp->next;
	}
	while (lst_th != NULL)
	{
		cl = (t_client *)lst_th->content;
		if (cl->end > size_tot)
		{
			ft_printf("%r#5 cl: %s\n",
					cl->name_host_cl);
			lst_th = lst_th->next;
			continue ;
		}
		get_stage_read(cl->sockfd, (cl->end - cl->start), cl->start, env);
		ret_msg = STAGE_SUCCES;
		send_message(cl->sockfd, sizeof(int), &ret_msg);
		lst_th = lst_th->next;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_key_hook(env->win, key_hook, env);
	mlx_expose_hook(env->win, expose_hook, env);
	ft_printf("End of compute, press esc to exit\n");
	mlx_loop(env->mlx);
}
