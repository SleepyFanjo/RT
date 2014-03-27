/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raythrow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 14:21:34 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/27 10:13:59 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "multithread.h"

void	calc_intersection(t_param *param, t_info *info)
{
	inter_sphere(info, param->sphere);
	inter_plane(info, param->plane);
	inter_cylinder(info, param->cylinder);
	inter_cone(info, param->cone);
	calc_normal(info);
}

int		raythrow(t_thread *thread)
{
	t_limit	*l;

	l = thread->limit;
	if (l->s_j == l->e_j)
	{
		return (one_line(thread, l));
	}
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
	t_info		*info;
	int			finl_color;

	info = init_info(param, i, j);
	calc_intersection(param, info);
	if (param->t->render || param->t->live)
	{
		finl_color = calc_color_end(param, info);
		write_on_img(param, finl_color, i, j);
	}
	else
		write_on_img(param, final_color(info->color, 1), i, j);
	free(info);
	return (0);
}
