/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 19:17:52 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/26 20:59:02 by qchevrin         ###   ########.fr       */
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

static double	*delta(t_line new, t_cylinder *obj)
{
	t_equa		e;
	double		*x;

	x = (double *)j_malloc(sizeof(double) * 2);
	x[0] = -1;
	x[1] = -1;
	e.a = SQR(new.vec.x) + SQR(new.vec.z);
	e.b = 2 * (new.pos.x * new.vec.x + new.pos.z * new.vec.z);
	e.c = SQR(new.pos.x) + SQR(new.pos.z) - SQR(obj->radius);
	e.delta = SQR(e.b) - 4 * e.a * e.c;
	if (e.delta < -0.00001)
		return (x);
	if (e.delta > -0.00001 && e.delta < 0.00001)
	{
		x[0] = (-e.b / (2 * e.a));
		return (x);
	}
	x[0] = (-e.b - sqrt(e.delta)) / (2 * e.a);
	x[1] = (-e.b + sqrt(e.delta)) / (2 * e.a);
	if (x[0] < x[1] && x[0] > 0)
		return (x);
	swap_double(&(x[0]), &(x[1]));
	return (x);
}

void			inter_cylinder(t_info *info, t_list *cylinder)
{
	t_line		new;
	t_cylinder	*obj;
	double		*dist;

	while (cylinder)
	{
		obj = (t_cylinder *)cylinder->content;
		new = get_new_equa(obj, info->r_line);
		dist = delta(new, obj);
		dist[0] = limited_cylinder(obj, new, dist);
		if (dist[0] > 0.001 && (info->distance < 0 || dist[0] < info->distance))
			update_info(info, dist[0], cylinder->content, new);
		cylinder = cylinder->next;
		free(dist);
	}
}
