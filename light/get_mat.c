#include "light.h"

double		get_shine(t_info *info)
{
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

double		get_med(t_info *info)
{
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

int			get_texture(t_info *info)
{
	if (info->obj_type == SPHERE)
		return ((int)(10.0 * ((t_sphere *)(info->obj))->mat.refrax));
	if (info->obj_type == PLANE)
		return ((int)(10.0 * ((t_plane *)(info->obj))->mat.refrax));
	if (info->obj_type == CYLINDER)
		return ((int)(10.0 * ((t_cylinder *)(info->obj))->mat.refrax));
	if (info->obj_type == CONE)
		return ((int)(10.0 * ((t_cone *)(info->obj))->mat.refrax));
	return (0);
}
