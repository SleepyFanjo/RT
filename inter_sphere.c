/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 17:07:16 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/21 12:40:37 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static void		update_info(t_info *info, double dist, void *obj)
{
	t_sphere	*sphere;

	info->distance = dist;
	info->obj_type = SPHERE;
	info->obj = obj;
	sphere = (t_sphere *)obj;
	info->color = sphere->color;
}

static t_line	get_new_equa(t_sphere *obj, t_line line)
{
	t_line		new;

	new.pos.x = line.pos.x;
	new.pos.y = line.pos.y;
	new.pos.z = line.pos.z;
	new.vec.x = line.vec.x;
	new.vec.y = line.vec.y;
	new.vec.z = line.vec.z;
	apply_trans(obj->pos, &(new.pos), -1);
	return (new);
}

static double	delta(t_line new, t_sphere *obj)
{
	t_equa		e;
	double		x1;
	double		x2;

	e.a = SQR(new.vec.x) + SQR(new.vec.y) + SQR(new.vec.z);
	e.b = 2 * (new.pos.x * new.vec.x + new.pos.y * new.vec.y);
	e.b = e.b + 2 * (new.pos.z * new.vec.z);
	e.c = SQR(new.pos.x) + SQR(new.pos.y) + SQR(new.pos.z) - SQR(obj->radius);
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


void			inter_sphere(t_param *param, t_info *info, t_list *sphere)
{
	t_line		new;
	t_sphere	*obj;
	double		dist;

	(void)param;
	while (sphere)
	{
		obj = (t_sphere *)sphere->content;
		new = get_new_equa(obj, info->r_line);
		dist = delta(new, obj);
	//	dist = limited_sphere(obj, new, dist);
		if (dist > 0 && (info->distance < 0 || dist < info->distance))
			update_info(info, dist, sphere->content);
		sphere = sphere->next;
	}
}
