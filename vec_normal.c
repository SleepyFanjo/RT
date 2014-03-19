/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 12:14:41 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/19 18:40:18 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_coord		sphere_vec_n(t_info *info, t_sphere *obj)
{
	t_coord		res;

	res.x = info->r_pos.x - obj->pos.x;
	res.y = info->r_pos.y - obj->pos.y;
	res.z = info->r_pos.z - obj->pos.z;
	return (res);
}

t_coord		plane_vec_n(t_plane *obj)
{
	t_coord		res;

	res.x = obj->vec.x;
	res.y = obj->vec.y;
	res.z = obj->vec.z;
	return (res);
}

t_coord		cylinder_vec_n(t_info *info, t_cylinder *obj)
{
	t_coord		res;

	res.x = info->s_pos.x;
	res.y = 0;
	res.z = info->s_pos.z;
	apply_rotrans(obj->rot, obj->pos, &res, -1);
	return (res);
}

t_coord		cone_vec_n(t_info *info, t_cone *obj)
{
	t_coord		res;

	res.x = info->s_pos.x;
	res.y = tan(RAD(obj->alpha));
	res.y = -SQR(res.y) * info->s_pos.y;
	res.z = info->s_pos.z;
	apply_rotrans(obj->rot, obj->pos, &res, -1);
	return (res);
}
