/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 15:49:52 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/19 18:40:26 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

void		fill_matrix_trans(double *matrix, t_coord trans)
{
    matrix[0] = 1;
    matrix[1] = 0;
    matrix[2] = 0;
    matrix[3] = trans.x;
    matrix[4] = 0;
    matrix[5] = 1;
    matrix[6] = 0;
    matrix[7] = trans.y;
    matrix[8] = 0;
    matrix[9] = 0;
    matrix[10] = 1;
    matrix[11] = trans.z;
    matrix[12] = 0;
    matrix[13] = 0;
    matrix[14] = 0;
    matrix[15] = 1;
}

static void	apply_tab(double *tab, double *matrix)
{
	matrix[0] = tab[P_C] * tab[P_E];
	matrix[1] = -tab[P_C] * tab[P_F];
	matrix[2] = tab[P_D];
	matrix[4] = -tab[P_BD] * tab[P_E] + tab[P_A] * tab[P_F];
	matrix[5] = tab[P_BD] * tab[P_F] + tab[P_A] * tab[P_E];
	matrix[6] = -tab[P_B] * tab[P_C];
	matrix[8] = tab[P_AD] * tab[P_E] + tab[P_B] * tab[P_F];
	matrix[9] = -tab[P_AD] * tab[P_F] + tab[P_B] * tab[P_E];
	matrix[10] = tab[P_A] * tab[P_C];
	matrix[3] = 0;
	matrix[7] = 0;
	matrix[11] = 0;
	matrix[12] = 0;
	matrix[13] = 0;
	matrix[14] = 0;
	matrix[15] = 1;
}

void		fill_matrix_rot(double *matrix, t_coord rot)
{
	double		tab[8];

	tab[0] = cos(RAD(rot.x));
	tab[1] = sin(RAD(rot.x));
	tab[2] = cos(RAD(rot.y));
	tab[3] = sin(RAD(rot.y));
	tab[4] = cos(RAD(rot.z));
	tab[5] = sin(RAD(rot.z));
	tab[6] = tab[0] * tab[3];
	tab[7] = tab[1] * tab[3];
	apply_tab(tab, matrix);
}