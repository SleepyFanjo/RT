/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:44:54 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/27 02:46:11 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

double	norme(t_coord vect)
{
	return (sqrt(SQR(vect.x) + SQR(vect.y) + SQR(vect.z)));
}

double	dot_product(t_coord p1, t_coord p2)
{
	double	tmp;

	tmp = p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
	return (tmp);
}

t_coord	normalize(t_coord vec)
{
	t_coord	n_vec;
	double	norm;

	norm = norme(vec);
	n_vec.x = vec.x / norm;
	n_vec.y = vec.y / norm;
	n_vec.z = vec.z / norm;
	return (n_vec);
}

t_coord	calc_v_reflex(t_coord ov_dir, t_coord ov_nor)
{
	double	tmp;
	t_coord	v_reflex;
	t_coord	v_dir;
	t_coord	v_nor;

	v_dir = normalize(ov_dir);
	v_nor = normalize(ov_nor);
	tmp = -2 * dot_product(v_dir, v_nor);
	v_reflex.x = v_dir.x + tmp * v_nor.x;
	v_reflex.y = v_dir.y + tmp * v_nor.y;
	v_reflex.z = v_dir.z + tmp * v_nor.z;
	return (v_reflex);
}

void	calc_reflex_color(int **col, int *obj_col, double reflex)
{
	(*col)[0] = reflex * obj_col[0] + (1 - reflex) * (*col)[0];
	(*col)[1] = reflex * obj_col[1] + (1 - reflex) * (*col)[1];
	(*col)[2] = reflex * obj_col[2] + (1 - reflex) * (*col)[2];
}
