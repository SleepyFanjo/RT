/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limited_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 16:40:55 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/26 17:11:29 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

double		limited_cylinder(t_cylinder *obj, t_line line, double dist)
{
	t_coord		pos;

	if (dist < 0 || !obj->is_limited)
		return (dist);
	pos.y = line.pos.y + dist * line.vec.y;
	if (pos.y > obj->lim_h || pos.y < obj->lim_b)
		dist = -1;
	return (dist);
}

double		limited_cone(t_cone *obj, t_line line, double dist)
{
	t_coord		pos;

	if (dist < 0 || !obj->is_limited)
		return (dist);
	pos.y = line.pos.y + dist * line.vec.y;
	if (pos.y > obj->lim_h || pos.y < obj->lim_b)
		dist = -1;
	return (dist);
}
