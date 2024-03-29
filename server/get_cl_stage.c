/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cl_stage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 11:57:16 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 11:57:16 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	loop_get_st_rd(int sockfd, int size, int *pos, char *buff)
{
	int		ask_size;
	int		ret;

	ask_size = size - *pos;
	if (ask_size > NET_BUFF_SIZE)
		ask_size = NET_BUFF_SIZE;
	ret = read(sockfd, buff, ask_size);
	if (ret < 0)
	{
		ft_printf("%rError #1\n");
		return (-1);
	}
	*pos += ret;
	return (ret);
}

static void	get_stage_read(int sockfd, int size, int start, t_v_env *env)
{
	char		*buff;
	int			pos;
	int			ret;
	int			nb_loop;

	buff = j_malloc(sizeof(char) * (NET_BUFF_SIZE + 10));
	pos = 0;
	cpy_to_img(start, NULL, -1, NULL);
	nb_loop = 0;
	while (pos < size)
	{
		if ((ret = loop_get_st_rd(sockfd, size, &pos, buff)) < 0)
			return ;
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
	}
	free(buff);
}

static void	get_lim_cl(t_list *lst)
{
	t_client	*cl;
	int			ret_msg;

	while (lst != NULL)
	{
		cl = (t_client *)lst->content;
		if (get_value(cl->sockfd, (void *)&(cl->start), sizeof(int)) < 0)
		{
			ft_printf("%r#3 cl: %s\n", cl->name_host_cl);
			lst = lst->next;
			continue ;
		}
		if (get_value(cl->sockfd, (void *)&(cl->end), sizeof(int)) < 0)
		{
			ft_printf("%r#4 cl: %s\n", cl->name_host_cl);
			lst = lst->next;
			continue ;
		}
		ret_msg = SIZE_SUCCES;
		send_message(cl->sockfd, sizeof(int), &ret_msg);
		lst = lst->next;
	}
}

void		get_cl_stage(t_list *lst_th, t_v_env *env)
{
	t_client	*cl;
	int			size_tot;
	int			ret_msg;

	size_tot = HEIGHT * env->line;
	get_lim_cl(lst_th);
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
		close(cl->sockfd);
		lst_th = lst_th->next;
	}
}
