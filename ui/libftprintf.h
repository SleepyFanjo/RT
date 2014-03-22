/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 12:13:15 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/22 23:14:40 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct		s_printf_env
{
	va_list			ap;
	char			*format;
	int				pos;
	int				len;
	int				fd;
}					t_printf_env;

int				l_printf(const char *format, ...);
void			ft_string(t_printf_env *e, char *s);
void			ft_putstr(char const *s);
void			ft_putnbr(int n);
char			*ft_itoa(int n);
void			ft_putui(unsigned long n, int base, int fd);
char			*ft_uitoa(unsigned long n, int base, int fd);
void			ft_bzero(void *s, size_t n);
char			*ft_strnew(size_t size);
void			ft_putchar(char c);
size_t			ft_strlen(const char *s);
void			ft_num(t_printf_env *e, int num);
void			ft_unsigned(t_printf_env *e, unsigned long num, int base);
void			ft_put_maj_hexa(unsigned int n, int base, int fd);
void			ft_maj_hexa(t_printf_env *e, unsigned int num);
#endif
