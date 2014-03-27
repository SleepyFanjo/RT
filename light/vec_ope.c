/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_ope.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:47:20 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/27 03:23:02 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_coord	calc_vec(t_coord p1, t_coord p2)
{
	t_coord	n_p;

	n_p.x = p2.x - p1.x;
	n_p.y = p2.y - p1.y;
	n_p.z = p2.z - p1.z;
	return (n_p);
}

double	ft_abs(double nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int		point_cmp(t_coord p1, t_coord p2)
{
	if (ft_abs(p1.x - p2.x) > 0.0001)
		return (0);
	if (ft_abs(p1.y - p2.y) > 0.0001)
		return (0);
	if (ft_abs(p1.z - p2.z) > 0.0001)
		return (0);
	return (1);
}

t_coord	turn_vect(t_coord vect)
{
	t_coord	n_vect;

	n_vect.x = -vect.x;
	n_vect.y = -vect.y;
	n_vect.z = -vect.z;
	return (n_vect);
}

t_coord	init_vec_tx(double x, double y, double z)
{
	t_coord	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}
