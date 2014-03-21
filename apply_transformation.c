/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_transformation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:38:55 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/19 18:40:21 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <matrix.h>

void	apply_trans(t_coord translation, t_coord *to_move, int mult)
{
	to_move->x = to_move->x + (translation.x * mult);
	to_move->y = to_move->y + (translation.y * mult);
	to_move->z = to_move->z + (translation.z * mult);
}

void	apply_rot(t_coord rotation, t_coord *to_rot, int mult)
{
	double		*matrix;
	double		*result;

	matrix = (double *)j_malloc(sizeof(double) * 16);
	result = (double *)j_malloc(sizeof(double) * 16);
	fill_matrix_rot(matrix, rotation);
	if (mult == -1)
	{
		invert_matrix(result, matrix);
		apply_matrix(result, to_rot);
	}
	else
		apply_matrix(matrix, to_rot);
	free(matrix);
	free(result);
}

void	apply_rotrans(t_coord rot, t_coord trans, t_coord *move, int mult)
{
	double		*trans_m;
	double		*rot_m;
	double		*tot;
	double		*result;

	trans_m = (double *)j_malloc(sizeof(double) * 16);
	rot_m = (double *)j_malloc(sizeof(double) * 16);
	result = (double *)j_malloc(sizeof(double) * 16);
	tot = (double *)j_malloc(sizeof(double) * 16);
	fill_matrix_rot(rot_m, rot);
	fill_matrix_trans(trans_m, trans);
	multiply_matrix(tot, trans_m, rot_m);
	if (mult < 0)
	{
		invert_matrix(result, tot);
		apply_matrix(result, move);
	}
	else
		apply_matrix(tot, move);
	free(trans_m);
	free(rot_m);
	free(tot);
	free(result);
}
