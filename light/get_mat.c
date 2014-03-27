/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:56:46 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/27 02:56:48 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

double		get_shine(t_info *info)
{
	if (info->obj_type == -1)
		return (0.0);
	if (info->obj_type == SPHERE)
		return (((t_sphere *)(info->obj))->mat.shine);
	if (info->obj_type == PLANE)
		return (((t_plane *)(info->obj))->mat.shine);
	if (info->obj_type == CYLINDER)
		return (((t_cylinder *)(info->obj))->mat.shine);
	if (info->obj_type == CONE)
		return (((t_cone *)(info->obj))->mat.shine);
	return (0.0);
}

double		get_reflex(t_info *info)
{
	if (info->obj_type == -1)
		return (-1.0);
	if (info->obj_type == SPHERE)
		return (((t_sphere *)(info->obj))->mat.reflex);
	if (info->obj_type == PLANE)
		return (((t_plane *)(info->obj))->mat.reflex);
	if (info->obj_type == CYLINDER)
		return (((t_cylinder *)(info->obj))->mat.reflex);
	if (info->obj_type == CONE)
		return (((t_cone *)(info->obj))->mat.reflex);
	return (-1.0);
}

double		get_med(t_info *info)
{
	if (info->obj_type == -1)
		return (0.0);
	if (info->obj_type == SPHERE)
		return (((t_sphere *)(info->obj))->mat.med_in);
	if (info->obj_type == PLANE)
		return (((t_plane *)(info->obj))->mat.med_in);
	if (info->obj_type == CYLINDER)
		return (((t_cylinder *)(info->obj))->mat.med_in);
	if (info->obj_type == CONE)
		return (((t_cone *)(info->obj))->mat.med_in);
	return (0.0);
}

double		get_refrax(t_info *info)
{
	if (info->obj_type == -1)
		return (0.0);
	if (info->obj_type == SPHERE)
		return (((t_sphere *)(info->obj))->mat.refrax);
	if (info->obj_type == PLANE)
		return (((t_plane *)(info->obj))->mat.refrax);
	if (info->obj_type == CYLINDER)
		return (((t_cylinder *)(info->obj))->mat.refrax);
	if (info->obj_type == CONE)
		return (((t_cone *)(info->obj))->mat.refrax);
	return (0.0);
}

double		get_trans(t_info *info)
{
	if (info->obj_type == -1)
		return (0.0);
	if (info->obj_type == SPHERE)
		return (((t_sphere *)(info->obj))->mat.trans);
	if (info->obj_type == PLANE)
		return (((t_plane *)(info->obj))->mat.trans);
	if (info->obj_type == CYLINDER)
		return (((t_cylinder *)(info->obj))->mat.trans);
	if (info->obj_type == CONE)
		return (((t_cone *)(info->obj))->mat.trans);
	return (0.0);
}
