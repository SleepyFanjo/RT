/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:51:48 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/19 14:57:53 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	if ((ptr = malloc((size + 10) * sizeof(char))) == NULL)
	{
		return (NULL);
	}
	while (size > 0)
	{
		ptr[size - 1] = '\0';
		size = size - 1;
	}
	return (ptr);
}
