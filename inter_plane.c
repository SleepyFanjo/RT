/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 12:17:47 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/19 10:44:55 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static void		update_info(t_info *info, float dist, void *obj)
{
	t_plane		*plane;

	info->distance = dist;
	info->obj_type = PLANE;
	info->obj = obj;
	plane = (t_plane *)obj;
	info->color = plane->color;
	info->pos.x = info->line.pos.x + dist * info->line.vec.x;
	info->pos.y = info->line.pos.y + dist * info->line.vec.y;
	info->pos.z = info->line.pos.z + dist * info->line.vec.z;
}

static float	delta(t_plane *plane, t_line new)
{
	float		distance;
	float		up;

	up = plane->vec.x * new.pos.x + plane->vec.y * new.pos.y;
	up = up + plane->vec.z * new.pos.z + plane->d;
	distance = plane->vec.x * new.vec.x + plane->vec.y * new.vec.y;
	distance = distance + plane->vec.z * new.vec.z;
	return (-(up / distance));
}

void			inter_plane(t_param *param, t_info *info, t_list *plane)
{
	t_plane		*obj;
	float		dist;

	(void)param;
	while (plane)
	{
		obj = (t_plane *)plane->content;
		dist = delta(obj, info->line);
		if (dist > 0 && (info->distance < 0 || dist < info->distance))
			update_info(info, dist, plane->content);
		plane = plane->next;
	}
}
