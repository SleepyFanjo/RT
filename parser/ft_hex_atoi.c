/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:17:59 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 16:14:37 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static int	get_value(char c)
{
	if (ft_isdigit(c))
	{
		return (c - '0');
	}
	return (c - 'A' + 10);
}

void		*free_spot(void *data)
{
	t_spot	*spot;

	spot = (t_spot *)data;
	free(spot->color);
	free(spot);
	return (NULL);
}

int			ft_hex_atoi(char *str)
{
	int		res;

	res = get_value(str[1]);
	res += get_value(str[0]) * 16;
	return (res);
}
