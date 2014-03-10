/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:18:04 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/10 16:27:16 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static void		init_line(t_param *param, int i, int j, t_line *line)
{
	line->pos->x = 0;
	line->pos->y = 0;
	line->pos->z = 0;
	line->vec->x = -(WIDTH / 2) + j;
	line->vec->y = (HEIGHT / 2) + j;
	line->vec->z = 1000;
	apply_trans(line->pos, param->cam, 1);
	apply_rot(line->vec, param->cam_rot, 1);
}

t_info			*init_info(t_param *param, int i, int j);
{
	t_info		*info;

	info = (t_info *)j_malloc(sizeof(t_info));
	info->line = (t_line *)j_malloc(sizeof(t_info));
	info->pos = (t_coord *)j_malloc(sizeof(t_coord));
	info->vec_n = (t_coord *)j_malloc(sizeof(t_coord));
	info->vec_r = (t_coord *)j_malloc(sizeof(t_coord));
	info->line->pos = (t_coord *)j_malloc(sizeof(t_coord));
	info->line->vec = (t_coord *)j_malloc(sizeof(t_coord));
	init_line(param, i, j, info->line);
	info->distance = -1;
	info->light = 0.0;
	return (info);
}
