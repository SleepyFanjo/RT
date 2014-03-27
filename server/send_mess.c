/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_mess.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 12:07:14 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 15:24:05 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/network.h"

static void	v_exit(char *msg, int cd)
{
	ft_printf(msg);
	exit(cd);
}

int			send_long_message(int sockfd, void *mess, int size)
{
	int		pos;
	int		ret;
	int		test;

	pos = 0;
	test = 0;
	while (pos < size)
	{
		ret = write(sockfd, mess + pos, size - pos);
		if (ret < 0)
		{
			ft_printf("%r#21\n");
			return (-1);
		}
		if (ret == 0)
			test++;
		if (test == LIM_NB_WRITE)
			v_exit("%r#10\n", 10);
		pos += ret;
	}
	return (0);
}

int			send_message(int fd, size_t size, void *mess)
{
	if (write(fd, mess, size) < 0)
	{
		ft_printf("%r22\n");
		close(fd);
		return (1);
	}
	return (0);
}
