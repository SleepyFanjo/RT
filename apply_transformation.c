/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_transformation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:38:55 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/10 16:26:58 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	apply_trans(t_coord *translation, t_coord *to_move, int mult)
{
	to_move->x = to_move->x + (translation->x * mult);
	to_move->y = to_move->y + (translation->y * mult);
	to_move->z = to_move->z + (translation->z * mult);
}

void	apply_rot_x(t_coord *vec, float rot_x)
{
	vec->x = vec->x;
	vec->y = vec->y * cos(RAD(rot_x)) - vec->z * sin(RAD(rot_x));
	vec->z = vec->y * sin(RAD(rot_x)) + vec->z * cos(RAD(rot_x));
}

void	apply_rot_y(t_coord *vec, float rot_y)
{
	vec->x = vec->x * cos(RAD(rot_y)) + vec->z * sin(RAD(rot_y));
	vec->y = vec->y;
	vec->z = -(vec->x) * sin(RAD(rot_y)) + vec->z * cos(RAD(rot_y));
}

void	apply_rot_z(t_coord *vec, float rot_z)
{
	vec->x = vec->x * cos(RAD(rot_z)) - vec->y * sin(RAD(rot_z));
	vec->y = vec->y * sin(RAD(rot_z)) + vec->y * cos(RAD(rot_z));
	vec->z = vec->z;
}

void	apply_rot(t_coord *rotation, t_coord *to_move, int mult)
{
	apply_rot_x(to_move, rotation->x * mult);
	apply_rot_y(to_move, rotation->y * mult);
	apply_rot_z(to_move, rotation->z * mult);
}
