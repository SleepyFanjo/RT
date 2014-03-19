/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limited_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 17:18:46 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/18 17:56:20 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

float		limited_sphere(t_sphere *obj, t_line line, float dist)
{
	float		pos_x;
	float		pos_y;
	float		pos_z;

	if (dist < 0)
		return (dist);
	pos_x = line.pos.x + dist * line.vec.x;
	pos_y = line.pos.y + dist * line.vec.y;
	pos_z = line.pos.z + dist * line.vec.z;
	if (pos_x > obj->lim_h_x || pos_x < obj->lim_b_x)
		return (-1);
	if (pos_y > obj->lim_h_y || pos_y < obj->lim_b_y)
		return (-1);
	if (pos_z > obj->lim_h_z || pos_z < obj->lim_b_z)
		return (-1);
	return (dist);
}
