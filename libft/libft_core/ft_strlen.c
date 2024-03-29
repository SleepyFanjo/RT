/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:17:24 by qchevrin          #+#    #+#             */
/*   Updated: 2013/12/16 16:41:15 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		i = i + 1;
	}
	return (i);
}
