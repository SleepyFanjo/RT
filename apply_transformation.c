/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_transformation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:38:55 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/21 13:08:03 by qchevrin         ###   ########.fr       */
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
	double		matrix[16];

	fill_matrix_rot(matrix, rotation);
	if (mult == -1)
		invert_matrix(matrix);
	apply_matrix(matrix, to_rot);
}
