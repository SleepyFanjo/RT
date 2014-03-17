/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 12:17:47 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/15 20:06:11 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static void		update_info(t_info *info, float dist, void *obj)
{
	info->distance = dist;
	info->obj_type = PLANE;
	info->obj = obj;
	info->pos.x = info->line.pos.x + dist * info->line.vec.x;
	info->pos.y = info->line.pos.y + dist * info->line.vec.y;
	info->pos.z = info->line.pos.z + dist * info->line.vec.z;
}

static t_line	get_new_equa(t_plane *obj, t_line line)
{
	t_line		new;

	new.pos.x = line.pos.x;
	new.pos.y = line.pos.y;
	new.pos.z = line.pos.z;
	new.vec.x = line.vec.x;
	new.vec.y = line.vec.y;
	new.vec.z = line.vec.z;
	apply_trans(obj->pos, &(new.pos), -1);
	apply_rot(obj->rot, &(new.vec), -1);
	return (new);
}

static float	delta(float d, t_line new)
{
	return (-(new.pos.y + d / new.vec.y));
}

void			inter_plane(t_param *param, t_info *info, t_list *plane)
{
	t_line		new;
	t_plane		*obj;
	float		dist;

	while (plane)
	{
		obj = (t_plane *)plane->content;
		new = get_new_equa(obj, info->line);
		dist = delta(-(obj->pos->y), new);
		if (dist > 0 && (info->distance < 0 || dist < info->distance))
			update_info(info, dist, plane->content);
		plane = plane->next;
	}
}
