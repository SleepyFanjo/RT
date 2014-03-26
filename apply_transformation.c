/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_transformation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:38:55 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/26 10:30:58 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <matrix.h>

static double	*matrix_cpy(double *dest, double *src)
{
	int			i;

	i = 0;
	while (i < 16)
	{
		dest[i] = src[i];
		i = i + 1;
	}
	return (dest);
}

void			apply_trans(t_coord tr, t_coord rot, t_coord *move, int mult)
{
	double		*matrix;
	double		*cpy;

	matrix = (double *)j_malloc(sizeof(double) * 16);
	cpy = (double *)j_malloc(sizeof(double) * 16);
	fill_matrix_rot(matrix, rot);
	fill_matrix_trans(matrix, tr);
	if (mult == -1)
		invert_matrix(matrix, matrix_cpy(cpy, matrix));
	apply_transformation(matrix, move);
	free(matrix);
	free(cpy);
}

void			apply_rot(t_coord rotation, t_coord *to_rot, int mult)
{
	double		*matrix;
	double		*cpy;

	matrix = (double *)j_malloc(sizeof(double) * 16);
	cpy = (double *)j_malloc(sizeof(double) * 16);
	fill_matrix_rot(matrix, rotation);
	if (mult == -1)
		invert_matrix(matrix, matrix_cpy(cpy, matrix));
	apply_matrix(matrix, to_rot);
	free(matrix);
	free(cpy);
}

void			apply_rot_norm(t_coord rotation, t_coord *to_rot, int mult)
{
	double		*matrix;
	double		*cpy;

	matrix = (double *)j_malloc(sizeof(double) * 16);
	cpy = (double *)j_malloc(sizeof(double) * 16);
	fill_matrix_rot(matrix, rotation);
	if (mult == -1)
		invert_matrix(matrix, matrix_cpy(cpy, matrix));
	transpose_matrix(matrix, matrix_cpy(cpy, matrix));
	apply_matrix(matrix, to_rot);
	free(matrix);
	free(cpy);
}
