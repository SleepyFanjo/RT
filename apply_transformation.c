/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_transformation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:38:55 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/26 18:51:30 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <matrix.h>

void			apply_trans(double *m, t_coord *move)
{
	apply_transformation(m, move);
}

void			apply_rot(double *m, t_coord *move)
{
	apply_matrix(m, move);
}

void			apply_rot_norm(double *m, t_coord *move)
{
	double		*tmp;

	tmp = (double *)j_malloc(sizeof(double) * 16);
	transpose_matrix(tmp, m);
	apply_matrix(tmp, move);
	free(tmp);
}

void			calc_matrix(void *obj, int obj_type)
{
	double		*m;
	double		*m_i;

	m = (double *)j_malloc(sizeof(double) * 16);
	m_i = (double *)j_malloc(sizeof(double) * 16);
	if (obj_type == SPHERE)
		calc_matrix_sphere(m, m_i, (t_sphere *)obj);
	else if (obj_type == PLANE)
		calc_matrix_plane(m, m_i, (t_plane *)obj);
	else if (obj_type == CONE)
		calc_matrix_cone(m, m_i, (t_cone *)obj);
	else if (obj_type == CYLINDER)
		calc_matrix_cylinder(m, m_i, (t_cylinder *)obj);
	else
		calc_matrix_cam(m, m_i, (t_param *)obj);
}
