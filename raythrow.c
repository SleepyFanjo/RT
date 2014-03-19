/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raythrow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 14:21:34 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/19 18:28:59 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "multithread.h"

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
	int		pop[3];

	if (light > 1)
		light = 1;
	if (color == NULL)
		return (0);
	pop[0] = color[0] * light;
	pop[1] = color[1] * light;
	pop[2] = color[2] * light;
	ret = pop[0] + 256 * pop[1]	+ 256 * 256 * pop[2];
	return (ret);
}

int		raythrow(t_thread *thread)
{
	t_limit	*l;

	l = thread->limit;
	if (l->s_j == l->e_j)
		return (one_line(thread, l));
	if (print_first_line(thread, l) < 0)
		return (-1);
	if (print_middle(thread, l) < 0)
		return (-1);
	if (print_last_line(thread, l) < 0)
		return (-1);
	return (0);
}

int		put_pixel_to_img(t_param *param, int i, int j)
{
	t_info		info;

	info = init_info(param, i, j);
	calc_intersection(param, &info);
	calc_light(param, &info, param->spot);
	write_on_img(param, calc_color(info.color, info.light), i, j);
	return (0);
}
