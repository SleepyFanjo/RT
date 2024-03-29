/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 11:00:36 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 11:04:09 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

static int	get_long_data(int sockfd, void *dest, int size)
{
	int			pos;
	int			ret;
	int			ask_size;

	pos = 0;
	while (pos < size)
	{
		ask_size = size - pos;
		if (ask_size > NET_BUFF_SIZE)
			ask_size = NET_BUFF_SIZE;
		ret = read(sockfd, dest + pos, ask_size);
		if (ret < 0)
			return (-1);
		pos += ret;
	}
	return (0);
}

static int	get_serv_tex(int sockfd, t_textures **tex)
{
	int			i;
	t_textures	*my_tex;
	int			size;

	i = 0;
	*tex = (t_textures *)j_malloc(sizeof(t_textures) * NB_T);
	my_tex = *tex;
	while (i < NB_T)
	{
		if (get_long_data(sockfd, my_tex + i, sizeof(t_textures)) < 0)
			return (-1);
		size = my_tex[i].sizeline * my_tex[i].size_y;
		my_tex[i].data = j_malloc(size);
		if (get_long_data(sockfd, my_tex[i].data, size) < 0)
			return (-1);
		i++;
	}
	return (0);
}

static void	v_exit(char *str, int cd)
{
	ft_printf(str);
	exit(cd);
}

void		get_env(int sockfd, t_inf_env *e)
{
	int		send;
	int		*decrgb;

	decrgb = j_malloc(sizeof(int) * 6);
	e->img->endian = -1;
	if (get_value(sockfd, e->img, sizeof(t_img)) < 0)
		v_exit("%rError: #14\n", 14);
	if (get_value(sockfd, decrgb, sizeof(int) * 6) < 0)
		v_exit("%rError: #14\n", 14);
	e->img->decrgb = decrgb;
	if (get_serv_tex(sockfd, &(e->t)) < 0)
		v_exit("%rError: #24\n", 24);
	e->event = j_malloc(sizeof(t_event));
	if (get_long_data(sockfd, e->event, sizeof(t_event)) < 0)
		v_exit("%rError #25\n", 25);
	send = SIZE_SUCCES;
	send_message(sockfd, sizeof(int), &send);
}
