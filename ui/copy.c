/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 09:43:55 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 14:28:34 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "ui.h"

int			*cpy_col(int *col)
{
	int		*new;

	if (!(new = (int *)malloc(sizeof(int) * 3)))
		exit (0);
	new[0] = col[0];
	new[1] = col[1];
	new[2] = col[2];
	return (new);
}

int			copy(int keycode, t_param *param)
{
	if (keycode != C)
		return (0);
	if (FOCUS == SPHERE)
		dup_sphere(param, param->sphere);
	if (FOCUS == PLANE)
		dup_plane(param, param->plane);
	if (FOCUS == CYLINDER)
		dup_cylinder(param, param->cylinder);
	if (FOCUS == CONE)
		dup_cone(param, param->cone);
	return (1);
}
