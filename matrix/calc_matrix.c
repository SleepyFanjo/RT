/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 11:54:07 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/26 14:12:17 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/matrix.h"

void		calc_matrix_sphere(double *m, double *m_i, t_sphere *obj)
{
	fill_matrix_rot(m, obj->rot);
	fill_matrix_trans(m, obj->pos);
	invert_matrix(m_i, m);
	obj->m = m;
	obj->m_i = m_i;
}

void		calc_matrix_plane(double *m, double *m_i, t_plane *obj)
{
	fill_matrix_rot(m, obj->vec);
	fill_matrix_trans(m, obj->pos);
	invert_matrix(m_i, m);
	obj->m = m;
	obj->m_i = m_i;
}

void		calc_matrix_cone(double *m, double *m_i, t_cone *obj)
{
	fill_matrix_rot(m, obj->rot);
	fill_matrix_trans(m, obj->pos);
	invert_matrix(m_i, m);
	obj->m = m;
	obj->m_i = m_i;
}

void		calc_matrix_cylinder(double *m, double *m_i, t_cylinder *obj)
{
	fill_matrix_rot(m, obj->rot);
	fill_matrix_trans(m, obj->pos);
	invert_matrix(m_i, m);
	obj->m = m;
	obj->m_i = m_i;
}
