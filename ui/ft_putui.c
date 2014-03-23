/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 20:19:11 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/23 20:13:13 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putui(unsigned long n, int base, int fd)
{
	char	*s;

	s = ft_uitoa(n, base);
	ft_putstr_fd(s, fd);
	free(s);
}
