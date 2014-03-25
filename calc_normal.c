/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 12:02:11 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/25 14:05:15 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static void	get_r_pos(t_info *info, t_coord *r_pos)
{
	r_pos->x = info->r_line.pos.x + info->distance * info->r_line.vec.x;
	r_pos->y = info->r_line.pos.y + info->distance * info->r_line.vec.y;
	r_pos->z = info->r_line.pos.z + info->distance * info->r_line.vec.z;
}

static void	get_s_pos(t_info *info, t_coord *s_pos)
{
	s_pos->x = info->s_line.pos.x + info->distance * info->s_line.vec.x;
	s_pos->y = info->s_line.pos.y + info->distance * info->s_line.vec.y;
	s_pos->z = info->s_line.pos.z + info->distance * info->s_line.vec.z;
}

void		calc_normal(t_info *info)
{
	if (info->distance < 0)
		return ;
	get_r_pos(info, &(info->r_pos));
	if (info->obj_type == CYLINDER || info->obj_type == CONE)
		get_s_pos(info, &(info->s_pos));
	else if (info->obj_type == PLANE)
		get_s_pos(info, &(info->s_pos));
	if (info->obj_type == SPHERE)
		info->vec_n = sphere_vec_n(info, (t_sphere *)info->obj);
	if (info->obj_type == PLANE)
		info->vec_n = plane_vec_n(info, (t_plane *)info->obj);
	if (info->obj_type == CYLINDER)
		info->vec_n = cylinder_vec_n(info, (t_cylinder *)info->obj);
	if (info->obj_type == CONE)
		info->vec_n = cone_vec_n(info, (t_cone *)info->obj);
}
