/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limited_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 17:18:46 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/21 16:33:24 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

double		limited_sphere(t_sphere *obj, t_line line, double *dist)
{
	t_coord		pos;

	if (dist[0] < 0)
		return (dist[0]);
	pos.x = line.pos.x + dist[0] * line.vec.x;
	pos.y = line.pos.y + dist[0] * line.vec.y;
	pos.z = line.pos.z + dist[0] * line.vec.z;
	if (pos.x > obj->lim_h_x || pos.x < obj->lim_b_x)
		dist[0] = -1;
	else if (pos.y > obj->lim_h_y || pos.y < obj->lim_b_y)
		dist[0] = -1;
	else if (pos.z > obj->lim_h_z || pos.z < obj->lim_b_z)
		dist[0] = -1;
	if (dist[0] < 0 && dist[1] > 0)
	{
		swap_double(&(dist[0]), &(dist[1]));
		return (limited_sphere(obj, line, dist));
	}
	return (dist[0]);
}
