/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:57:18 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/27 15:09:23 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	void		*ret;

	str = (const char *)s;
	while (*str != c)
	{
		if (n <= 0)
		{
			return (NULL);
		}
		str = str + 1;
		n = n - 1;
	}
	ret = (void*)str;
	return (ret);
}
