/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 12:14:41 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/26 11:36:59 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static t_coord	normal(t_coord vec)
{
	double		norme;
	t_coord		res;

	norme = sqrt(SQR(vec.x) + SQR(vec.y) + SQR(vec.z));
	res.x = vec.x / norme;
	res.y = vec.y / norme;
	res.z = vec.z / norme;
	return (res);
}

t_coord			sphere_vec_n(t_info *info, t_sphere *obj)
{
	t_coord		res;

	res.x = info->r_pos.x - obj->pos.x;
	res.y = info->r_pos.y - obj->pos.y;
	res.z = info->r_pos.z - obj->pos.z;
	apply_rot_norm(obj->m_i, &res);
	return (normal(res));
}

t_coord			plane_vec_n(t_info *info, t_plane *obj)
{
	t_coord		res;

	(void)info;
	res.x = 0;
	res.y = 100;
	res.z = 0;
	apply_rot_norm(obj->m_i, &res);
	return (normal(res));
}

t_coord			cylinder_vec_n(t_info *info, t_cylinder *obj)
{
	t_coord		res;

	res.x = info->s_pos.x;
	res.y = 0;
	res.z = info->s_pos.z;
	apply_rot_norm(obj->m_i, &res);
	return (normal(res));
}

t_coord			cone_vec_n(t_info *info, t_cone *obj)
{
	t_coord		res;

	res.x = info->s_pos.x;
	res.y = tan(RAD(obj->alpha));
	res.y = -SQR(res.y) * info->s_pos.y;
	res.z = info->s_pos.z;
	apply_rot_norm(obj->m_i, &res);
	return (normal(res));
}
