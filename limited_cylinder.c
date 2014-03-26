/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limited_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 16:40:55 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/26 21:16:35 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

double		limited_cylinder(t_cylinder *obj, t_line line, double *dist)
{
	t_coord		pos;

	if (dist[0] < 0 || !obj->is_limited)
		return (dist[0]);
	pos.y = line.pos.y + dist[0] * line.vec.y;
	if (pos.y > obj->lim_h || pos.y < obj->lim_b)
		dist[0] = -1;
	if (dist[0] < 0 && dist[1] > 0)
	{
		swap_double(&(dist[0]), &(dist[1]));
		return (limited_cylinder(obj, line, dist));
	}
	return (dist[0]);
}

double		limited_cone(t_cone *obj, t_line line, double *dist)
{
	t_coord		pos;

	if (dist[0] < 0 || !obj->is_limited)
		return (dist[0]);
	pos.y = line.pos.y + dist[0] * line.vec.y;
	if (pos.y > obj->lim_h || pos.y < obj->lim_b)
		dist[0] = -1;
	if (dist[0] < 0 && dist[1] > 0)
	{
		swap_double(&(dist[0]), &(dist[1]));
		return (limited_cone(obj, line, dist));
	}
	return (dist[0]);
}
