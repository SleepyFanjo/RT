/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_mess.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 11:06:49 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 11:06:50 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void		send_message(int fd, size_t size, void *mess)
{
	if (write(fd, mess, size) < 0)
	{
		ft_printf("%rFail to communicate with the server\n");
		close(fd);
		exit(1);
	}
}
