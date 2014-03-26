/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 17:07:16 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/26 15:46:22 by qchevrin         ###   ########.fr       */
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
	apply_trans(obj->m_i, &(new.pos));
	apply_rot(obj->m_i, &(new.vec));
	return (new);
}

static double	*delta(t_line new, t_sphere *obj)
{
	t_equa		e;
	double		*ret;

	ret = (double *)j_malloc(sizeof(double) * 2);
	ret[0] = -1;
	ret[1] = -1;
	e.a = SQR(new.vec.x) + SQR(new.vec.y) + SQR(new.vec.z);
	e.b = 2 * (new.pos.x * new.vec.x + new.pos.y * new.vec.y);
	e.b = e.b + 2 * (new.pos.z * new.vec.z);
	e.c = SQR(new.pos.x) + SQR(new.pos.y) + SQR(new.pos.z) - SQR(obj->radius);
	e.delta = SQR(e.b) - 4 * e.a * e.c;
	if (e.delta < -0.00001)
		return (ret);
	if (e.delta > -0.00001 && e.delta < 0.00001)
	{
		ret[0] = -e.b / (2 * e.a);
		return (ret);
	}
	ret[0] = (-e.b - sqrt(e.delta)) / (2 * e.a);
	ret[1] = (-e.b + sqrt(e.delta)) / (2 * e.a);
	if (ret[0] < ret[1] && ret[0] > 0)
		return (ret);
	swap_double(&(ret[0]), &(ret[1]));
	return (ret);
}


void			inter_sphere(t_info *info, t_list *sphere)
{
	t_line		new;
	t_sphere	*obj;
	double		*dist;

	while (sphere)
	{
		obj = (t_sphere *)sphere->content;
		new = get_new_equa(obj, info->r_line);
		dist = delta(new, obj);
		dist[0] = limited_sphere(obj, new, dist);
		if (dist[0] > 0.001 && (info->distance < 0 || dist[0] < info->distance))
			update_info(info, dist[0], sphere->content);
		sphere = sphere->next;
		free(dist);
	}
}
