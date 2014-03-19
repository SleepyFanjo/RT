/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raythrow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 14:21:34 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/19 14:57:44 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	calc_intersection(t_param *param, t_info *info)
{
	inter_sphere(param, info, param->sphere);
	inter_plane(param, info, param->plane);
	inter_cylinder(param, info, param->cylinder);
	inter_cone(param, info, param->cone);
}

static int		calc_color(int *color, float light)
{
	int		ret;

	(void)light;
	if (color == NULL)
		return (0);
	ret = color[0] + 256 * color[1] + 256 * 256 * color[2];
	return (ret);
}

int		raythrow(t_thread *thread)
{
	int		j;

	while (thread->limit.s_i <= thread->limit.e_i)
	{
		j = thread->limit.s_j;
		while (j <= thread->limit.e_j)
		{
			if (put_pixel_to_img(thread->p, thread->limit.s_i, j))
				return (-1);
			j = j + 1;
		}
		thread->limit.s_i = thread->limit.s_i + 1;
	}
	return (0);
}

int		put_pixel_to_img(t_param *param, int i, int j)
{
	t_info		info;

	info = init_info(param, i, j);
	calc_intersection(param, &info);
	//calc_light(param, &info);
	write_on_img(param, calc_color(info.color, info.light), i, j);
	return (0);
}
