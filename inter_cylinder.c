/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 19:17:52 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/17 15:36:22 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static void		update_info(t_info *info, float dist, void *obj)
{
	info->distance = dist;
	info->obj_type = CYLINDER;
	info->obj = obj;
	info->pos.x = info->line.pos.x + dist * info->line.vec.x;
	info->pos.y = info->line.pos.y + dist * info->line.vec.y;
	info->pos.z = info->line.pos.z + dist * info->line.vec.z;
}

static t_line	get_new_equa(t_cylinder *obj, t_line line)
{
	t_line		new;

	new.pos.x = line.pos.x;
	new.pos.y = line.pos.y;
	new.pos.z = line.pos.z;
	new.vec.x = line.vec.x;
	new.vec.y = line.vec.y;
	new.vec.z = line.vec.z;
	apply_trans(obj->pos, &new, -1);
	apply_rotation(obj->rot, &new, -1);
	return (new);
}

static float	delta(t_line new, t_cylinder *obj)
{
	t_equa		e;
	float		x1;
	float		x2;

	e.a = sqr(new.vec.x) + sqr(new.vec.y);
	e.b = 2 * (new.pos.x * new.vec.x + new.pos.y * new.vec.y);
	e.c = sqr(new.pos.x) + sqr(new.pos.y) - sqr(obj->radius);
	e.delta = sqr(e.b) - 4 * e.a * e.c;
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

void			inter_cylinder(t_param *param, t_info *info, t_list *cylinder)
{
	t_line		new;
	t_cylinder	*obj;
	float		dist;

	(void)param;
	while (cylinder)
	{
		obj = (t_cylinder *)cylinder->content;
		new = get_new_equq(obj, info->line);
		dist = delta(new, obj);
		if (dist > 0 && (info->distance < 0 || dist < info->distance))
			update_info(info, dist, cylinder->content);
		cylinder = cylinder->next;
	}
}
