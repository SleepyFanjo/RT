/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:22:27 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 15:22:34 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/network.h"

int		get_value(int fd, void *buf, size_t size)
{
	int		ret;
	int		nb_loop;

	ret = 0;
	nb_loop = 0;
	while (ret == 0)
	{
		ret = read(fd, buf, size);
		if (ret == 0)
			continue ;
		if (nb_loop > LIM_NB_READ && ret != (int)size)
			return (-1);
		usleep(100);
		nb_loop++;
	}
	return (0);
}
