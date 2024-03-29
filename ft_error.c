/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 11:17:34 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/25 11:55:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void		ft_error(char *s1, char *s2, int mode)
{
	ft_putstr_fd(s1, 2);
	if (s2 != NULL)
		ft_putstr_fd(s2, 2);
	ft_putstr_fd("\n", 2);
	if (mode)
		exit(mode);
}

void		*j_malloc(size_t size)
{
	void	*ret;

	if ((ret = malloc(size)) == NULL)
	{
		if ((ret = malloc(size)) == NULL)
			ft_error("Error : can't malloc", NULL, 1);
	}
	return (ret);
}
