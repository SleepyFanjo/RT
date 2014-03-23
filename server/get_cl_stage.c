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

	buff = malloc(sizeof(char) * (NET_BUFF_SIZE + 10));
	pos = 0;
	cpy_to_img(start, NULL, -1, NULL);
	ft_printf("size: %d\n", size);
	while (pos < size)
	{
		ask_size = size - pos;
		if (ask_size > NET_BUFF_SIZE)
			ask_size = NET_BUFF_SIZE;
		ft_printf("loop: pos: %d, ask_size: %d\n", pos, ask_size);
		ret = read(sockfd, buff, ask_size);
		if (ret < 0)
		{
			ft_printf("Fail #1\n");
			return ;
		}
		cpy_to_img(0, buff, ret, env);
		pos += ret;
	}
}

void		get_cl_stage(t_list *lst_th)
{
	t_v_env		*env;
	int			start;
	int			end;
	t_client	*cl;
	int			size_tot;
	int			ret_msg;

	env = malloc(sizeof(t_v_env));
	init_env(env);
	size_tot = HEIGHT * env->line;
	ft_printf("img->bpp: %d\n", env->line);
	ft_printf("Height: %d, W: %d\n", HEIGHT, WIDTH);
	while (lst_th != NULL)
	{
		cl = (t_client *)lst_th->content;
		if (get_value(cl->sockfd, (void *)&start, sizeof(int)) < 0)
		{
			ft_printf("%r#3 cl: %s\n", cl->name_host_cl);
			lst_th = lst_th->next;
			continue ;
		}
		if (get_value(cl->sockfd, (void *)&end, sizeof(int)) < 0)
		{
			ft_printf("%r#4 cl: %s\n", cl->name_host_cl);
			lst_th = lst_th->next;
			continue ;
		}
		ft_printf("start: %d, end: %d, size_tot: %d\n", start, end, size_tot);
		if (end > size_tot)
		{
			ft_printf("%r#5 cl: %s\n",
					cl->name_host_cl);
			lst_th = lst_th->next;
			continue ;
		}
		ret_msg = SIZE_SUCCES;
		send_message(cl->sockfd, sizeof(int), &ret_msg);
		ft_printf("get_stage\n");
		get_stage_read(cl->sockfd, (end - start), start, env);
		ft_printf("end get_stage\n");
		ret_msg = STAGE_SUCCES;
		ft_printf("send confirm\n");
		send_message(cl->sockfd, sizeof(int), &ret_msg);
		ft_printf("end send confirm\n");
		lst_th = lst_th->next;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_loop(env->mlx);
}
