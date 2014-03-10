/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raythrow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 14:21:34 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/10 18:13:21 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	calc_intersection(t_param *param, t_info *info)
{
	inter_sphere(param, info, param->sphere);
	inter_plane(param, info, param->plane);
	inter_cylindre(param, info, param->cylindre);
	inter_cone(param, info, param->cone);
}

int		raythrow(t_thread *thread)
{
	int		j;

	while (start_i <= end_i)
	{
		j = start_j;
		while (j <= end_j)
		{
			if (put_pixel_to_img(thread->p, start_i, j))
				return (-1);
			j = j + 1;
		}
		start_i = start_i + 1;
	}
	return (0);
}

int		put_pixel_to_img(t_param *param, int i, int j)
{
	t_info		*info;

	if ((info = init_info(param, i, j)) == NULL)
		return (1);
	calc_intersection(param, info);
	calc_light(param, info);
	write_on_img(param, calc_color(info->color, info->light), i, j);
	free_info(info);
	return (0);
}
