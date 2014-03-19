/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 11:06:20 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/19 14:17:33 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int			first_number(char *str, int *i)
{
	while (str[*i] != '-' && !ft_isdigit(str[*i]))
	{
		if (str[*i] == '\0')
			ft_error("Error : file incorrect, incomplete line", NULL, 1);
		*i = *i + 1;
	}
	return (*i);
}

int			next_number(char *line, int *i)
{
	while (line[*i] != ' ' && line[*i] != '\0')
		*i = *i + 1;
	while (line[*i] == ' ')
	{
		*i = *i + 1;
	}
	return (*i);
}
