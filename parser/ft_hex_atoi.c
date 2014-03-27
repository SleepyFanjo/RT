/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:17:59 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 15:27:36 by lredoban         ###   ########.fr       */
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

int			ft_hex_atoi(char *str)
{
	int		res;

	res = get_value(str[1]);
	res += get_value(str[0]) * 16;
	return (res);
}
