/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 22:03:24 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/22 22:35:55 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_num(t_printf_env *e, int num)
{
	if (num < 0)
		e->len += 1;
	if (num == 0)
	{
		ft_putchar_fd('0', e->fd);
		e->len += 1;
	}
	else
	{
		ft_putnbr_fd(num, e->fd);
		while (num != 0)
		{
			e->len += 1;
			num /= 10;
		}
	}
}

void		ft_unsigned(t_printf_env *e, unsigned long num, int base)
{
	if (num == 0)
	{
		ft_putchar_fd('0', e->fd);
		e->len += 1;
	}
	else
	{
		ft_putui(num, base, e->fd);
		while (num != 0)
		{
			e->len += 1;
			num /= base;
		}
	}
}

void		ft_maj_hexa(t_printf_env *e, unsigned int num)
{
	if (num == 0)
	{
		ft_putstr_fd("00", e->fd);
		e->len += 1;
	}
	else
	{
		ft_put_maj_hexa(num, 16, e->fd);
		while (num != 0)
		{
			e->len += 1;
			num /= 16;
		}
	}
}
