/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 22:10:51 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 09:05:52 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_hexatoa_len(unsigned int n, int base)
{
	int			len;

	len = 0;
	while (n != 0)
	{
		n /= base;
		len += 1;
	}
	return (len);
}

static char		*ft_hexatoa(unsigned int n, int base)
{
	int			len;
	int			lim;
	char		*str;

	lim = 0;
	len = ft_hexatoa_len(n, base);
	if (len == 1)
	{
		len = 2;
		lim = 1;
	}
	str = ft_strnew(len + 1);
	str[0] = '0';
	str[len] = '\0';
	while (len != lim)
	{
		len -= 1;
		if (n % base > 9)
			str[len] = 'A' - 10 + n % base;
		else
			str[len] = '0' + n % base;
		n /= base;
	}
	return (str);
}

void			ft_put_maj_hexa(unsigned int n, int base, int fd)
{
	char		*s;
	s = ft_hexatoa(n, base);
	ft_putstr_fd(s, fd);
	free(s);
}

void			ft_string(t_printf_env *e, char *s)
{
	if (!s)
	{
		ft_putstr_fd("(null)", e->fd);
		e->len += 6;
	}
	else
	{
		ft_putstr_fd(s, e->fd);
		e->len += ft_strlen(s);
	}
}
