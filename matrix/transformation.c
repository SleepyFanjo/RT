/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 10:16:40 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/26 10:24:05 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

void		fill_matrix_trans(double *matrix, t_coord trans)
{
	matrix[3] = trans.x;
	matrix[7] = trans.y;
	matrix[11] = trans.z;
}

void		apply_transformation(double *m, t_coord *p)
{
	t_coord		tmp;

	tmp.x = p->x * m[0] + p->y * m[1] + p->z * m[2] + m[3];
	tmp.y = p->x * m[4] + p->y * m[5] + p->z * m[6] + m[7];
	tmp.z = p->x * m[8] + p->y * m[9] + p->z * m[10] + m[11];
	p->x = tmp.x;
	p->y = tmp.y;
	p->z = tmp.z;
}
