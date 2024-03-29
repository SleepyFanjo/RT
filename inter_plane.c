/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 12:17:47 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/26 18:06:42 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static void		update_info(t_info *info, double dist, void *obj, t_line new)
{
	t_plane		*plane;

	info->distance = dist;
	info->obj_type = PLANE;
	info->obj = obj;
	plane = (t_plane *)obj;
	info->color = plane->color;
	info->s_line.pos.x = new.pos.x;
	info->s_line.pos.y = new.pos.y;
	info->s_line.pos.z = new.pos.z;
	info->s_line.vec.x = new.vec.x;
	info->s_line.vec.y = new.vec.y;
	info->s_line.vec.z = new.vec.z;
}

static double	delta(t_plane *plane, t_line new)
{
	(void)plane;
	if (new.vec.y > -0.0001 && new.vec.y < 0.0001)
		return (-1);
	return (-(new.pos.y / new.vec.y));
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
	apply_trans(obj->m_i, &new.pos);
	apply_rot(obj->m_i, &new.vec);
	return (new);
}

void			inter_plane(t_info *info, t_list *plane)
{
	t_plane		*obj;
	t_line		new;
	double		dist;

	while (plane)
	{
		obj = (t_plane *)plane->content;
		new = get_new_equa(obj, info->r_line);
		dist = delta(obj, new);
		if (dist > 0.001 && (info->distance < 0 || dist < info->distance))
			update_info(info, dist, plane->content, new);
		plane = plane->next;
	}
}
