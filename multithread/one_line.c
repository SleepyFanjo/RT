/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 10:43:03 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 10:43:30 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int		one_line(t_thread *th, t_limit *l)
{
	int		i;

	i = l->s_i;
	while (i < l->e_i)
	{
		if (put_pixel_to_img(th->p, l->s_j, i))
			return (-1);
		i++;
	}
	return (0);
}
