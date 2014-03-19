/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 19:17:52 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/18 16:44:56 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static void		update_info(t_info *info, float dist, void *obj)
{
	t_cone	*cone;

	info->distance = dist;
	info->obj_type = CONE;
	info->obj = obj;
	cone = (t_cone *)obj;
	info->color = cone->color;
	info->pos.x = info->line.pos.x + dist * info->line.vec.x;
	info->pos.y = info->line.pos.y + dist * info->line.vec.y;
	info->pos.z = info->line.pos.z + dist * info->line.vec.z;
}

static t_line	get_new_equa(t_cone *obj, t_line line)
{
	t_line		new;

	new.pos.x = line.pos.x;
	new.pos.y = line.pos.y;
	new.pos.z = line.pos.z;
	new.vec.x = line.vec.x;
	new.vec.y = line.vec.y;
	new.vec.z = line.vec.z;
	apply_trans(obj->pos, &new.pos, -1);
	apply_rot(obj->rot, &new.vec, -1);
	return (new);
}

static float	delta(t_line new, t_cone *obj)
{
	t_equa		e;
	float		tan_al;
	float		x1;
	float		x2;

	tan_al = tan(RAD(obj->alpha));
	tan_al = SQR(tan_al);
	e.a = SQR(new.vec.x) + SQR(new.vec.z) - (SQR(new.vec.y) * tan_al);
	e.b = 2 * (new.vec.x * new.pos.x + new.vec.z * new.pos.z);
	e.b = e.b - (2 * new.vec.y * new.pos.y * tan_al);
	e.c = SQR(new.pos.x) + SQR(new.pos.z) - (SQR(new.pos.y) * tan_al);
	e.delta = SQR(e.b) - 4 * e.a * e.c;
	if (e.delta < -0.00001)
		return (-1);
	if (e.delta > -0.00001 && e.delta < 0.00001)
		return (-e.b / (2 * e.a));
	x1 = (-e.b - sqrt(e.delta)) / (2 * e.a);
	x2 = (-e.b + sqrt(e.delta)) / (2 * e.a);
	if (x1 < x2 && x1 > 0)
		return (x1);
	return (x2);
}

void			inter_cone(t_param *param, t_info *info, t_list *cone)
{
	t_line		new;
	t_cone		*obj;
	float		dist;

	(void)param;
	while (cone)
	{
		obj = (t_cone *)cone->content;
		new = get_new_equa(obj, info->line);
		dist = delta(new, obj);
		if (dist > 0 && (info->distance < 0 || dist < info->distance))
			update_info(info, dist, cone->content);
		cone = cone->next;
	}
}
