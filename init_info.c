/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:18:04 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/26 18:03:17 by qchevrin         ###   ########.fr       */
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
	apply_trans(param->m_cam, &(line->pos));
	apply_rot(param->m_cam, &(line->vec));
}

t_info			*init_info(t_param *param, int i, int j)
{
	t_info		*info;

	info = (t_info *)j_malloc(sizeof(t_info));
	init_line(param, i, j, &(info->r_line));
	info->r_pos.x = 0;
	info->r_pos.y = 0;
	info->r_pos.z = 0;
	info->distance = -1;
	info->light = 0.0f;
	info->color = NULL;
	info->obj = NULL;
	info->obj_type = -1;
	return (info);
}
