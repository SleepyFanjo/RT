/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_stage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 11:06:57 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 11:06:58 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

static char	*init_var(t_param *p, int start, int end, int *size)
{
	t_img	*img;
	char	*addr;

	img = &(p->v_img);
	*size = end - start;
	addr = img->addr + start;
	return (addr);
}

static void	v_exit(char *msg, int cd)
{
	ft_printf(msg);
	exit(cd);
}

void		send_stage(int sockfd, t_param *p, int start, int end)
{
	int		pos;
	int		size;
	int		ret;
	int		test;
	char	*addr;

	pos = 0;
	test = 0;
	addr = init_var(p, start, end, &size);
	while (pos < size)
	{
		ret = write(sockfd, addr + pos, size - pos);
		if (ret < 0)
			v_exit("#9", 9);
		if (ret == 0)
			test++;
		if (test == LIM_NB_WRITE)
			v_exit("%r#10\n", 10);
		pos += ret;
	}
}
