/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 17:07:16 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/11 17:54:28 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static void		update_info(t_info *info, float dist, void *obj)
{
	info->distance = dist;
	info->obj_type = SPHERE;
	info->obj = obj;
	info->pos.x = info->line.pos.x + dist * info->line.vec.x;
	info->pos.y = info->line.pos.y + dist * info->line.vec.y;
	info->pos.z = info->line.pos.z + dist * info->line.vec.z;
}

static t_line	get_new_equa(t_sphere *obj, t_line line)
{
	t_line		new;

	new.x = line.x;
	new.y = line.y;
	new.z = line.z;
	apply_trans(obj->pos, &new, -1);
	return (new);
}

static float	delta(t_line line, t_sphere *obj)
{
	t_equq		e;
	float		x1;
	float		x2;

	e.a = sqr(new.vec.x) + sqr(new.vec.z) + sqr(new.vec.z);
	e.b = 2 * (new.pos.x * new.vec.x + new.pos.y * new.vec.y);
	e.b = e.b + 2 * (new.pos.z * new.vec.z);
	e.c = sqr(new.pos.x) + sqr(new.pos.y) + sqr(new.pos.z) - sqr(obj->radius);
	e.delta = sqr(e.b) - 4 * e.a * e.c;
	if (e.delta < -0.00001)
		return (-1);
	if (e.delta > -0.00001 && e.delta < 0.00001)
		return (-e.b / (2 * e.a));
	x1 = (-e.a - sqrt(e.delta)) / (2 * e.a);
	x2 = (-e.a + sqrt(e.delta)) / (2 * e.a);
	if (x1 < x2 && x1 > 0)
		return (x1);
	return (x2);
}


void			inter_sphere(t_param *param, t_info *info, t_list *sphere)
{
	t_line		new;
	t_sphere	*obj;
	float		dist;

	while (sphere)
	{
		obj = (t_sphere *)sphere->content;
		new = get_new_equa(obj, info->line);
		dist = delta(new, obj);
		if (dist > 0 && (info->distance < 0 || dist < info->distance))
			update_info(info, dist, sphere->content);
		sphere = sphere->next;
	}
}