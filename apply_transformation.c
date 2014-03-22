/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_transformation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:38:55 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/21 19:30:25 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <matrix.h>

void			apply_trans(t_coord translation, t_coord *to_move, int mult)
{
	to_move->x = to_move->x + (translation.x * mult);
	to_move->y = to_move->y + (translation.y * mult);
	to_move->z = to_move->z + (translation.z * mult);
}

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
