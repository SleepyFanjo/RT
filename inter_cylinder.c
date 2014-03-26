/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 19:17:52 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/26 11:33:40 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static void		update_info(t_info *info, double dist, void *obj, t_line new)
{
	t_cylinder	*cylinder;

	info->distance = dist;
	info->obj_type = CYLINDER;
	info->obj = obj;
	cylinder = (t_cylinder *)obj;
	info->color = cylinder->color;
	info->s_line.pos.x = new.pos.x;
	info->s_line.pos.y = new.pos.y;
	info->s_line.pos.z = new.pos.z;
	info->s_line.vec.x = new.vec.x;
	info->s_line.vec.y = new.vec.y;
	info->s_line.vec.z = new.vec.z;
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
	apply_trans(obj->m_i, &new.pos);
	apply_rot(obj->m_i, &new.vec);
	return (new);
}

static double	delta(t_line new, t_cylinder *obj)
{
	t_equa		e;
	double		x1;
	double		x2;

	e.a = SQR(new.vec.x) + SQR(new.vec.z);
	e.b = 2 * (new.pos.x * new.vec.x + new.pos.z * new.vec.z);
	e.c = SQR(new.pos.x) + SQR(new.pos.z) - SQR(obj->radius);
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

void			inter_cylinder(t_param *param, t_info *info, t_list *cylinder)
{
	t_line		new;
	t_cylinder	*obj;
	double		dist;

	(void)param;
	while (cylinder)
	{
		obj = (t_cylinder *)cylinder->content;
		new = get_new_equa(obj, info->r_line);
		dist = delta(new, obj);
		if (dist > 0.1 && (info->distance < 0 || dist < info->distance))
			update_info(info, dist, cylinder->content, new);
		cylinder = cylinder->next;
	}
}
