/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:18:04 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/22 11:44:33 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static void		init_line(t_param *param, int i, int j, t_line *line)
{
	line->pos.x = 0;
	line->pos.y = 0;
	line->pos.z = 0;
	line->vec.x = -(WIDTH / 2) + j;
	line->vec.y = (HEIGHT / 2) - i;
	line->vec.z = 1000;
	apply_trans(param->cam, &(line->pos), 1);
	apply_rot(param->rot_cam, &(line->vec), 1);
}

t_info			init_info(t_param *param, int i, int j)
{
	t_info		info;

	init_line(param, i, j, &(info.r_line));
	info.distance = -1;
	info.light = 0.0f;
	info.color = NULL;
	info.obj_type = -1;
	return (info);
}
