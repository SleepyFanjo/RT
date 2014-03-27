/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:50:53 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/27 08:23:26 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

double	calc_fading(t_coord v_dir, t_coord v_nor)
{
	double	tmp;

	tmp = dot_product(v_dir, v_nor);
	tmp = tmp / (norme(v_dir) * norme(v_nor));
	return (tmp);
}

double	calc_shining(t_coord v_nor, t_coord v_lum)
{
	double	shining;
	t_coord	v_reflex;

	v_reflex = calc_v_reflex(v_lum, v_nor);
	shining = pow(calc_fading(v_lum, v_reflex), 100);
	return (shining);
}

static t_line	init_line(t_coord p1, t_coord p2)
{
	t_line	line;

	line.vec.x = p1.x - p2.x;
	line.vec.y = p1.y - p2.y;
	line.vec.z = p1.z - p2.z;
	line.pos.x = p2.x;
	line.pos.y = p2.y;
	line.pos.z = p2.z;
	return (line);
}

t_info	*init_light(t_info *info, t_spot *spot)
{
	t_info	*light;

	light = (t_info *)j_malloc(sizeof(t_info));
	light->r_line = init_line(info->r_pos, spot->coord);
	light->distance = -1;
	light->light = 0.0f;
	light->color = (int *)j_malloc(sizeof(int) * 3);
	light->obj_type = -1;
	return (light);
}


void	calc_light(t_param *param, t_info *info, t_list *spot)
{
	t_info	*light;
	t_spot	*o_spot;
	t_lum	lum;
	int 	*s_color;

	if (info->distance < 0)
		return ;
	s_color = init_color();
	while (spot)
	{
		o_spot = (t_spot *)spot->content;
		light = init_light(info, o_spot);
		calc_intersection(param, light);
		if (point_cmp(info->r_pos, light->r_pos) == 1)
		{
			lum.fading = ft_abs(calc_fading(light->r_line.vec, info->vec_n));
			lum.shining = ft_abs(calc_shining(info->vec_n, light->r_line.vec));
			info->light += o_spot->value * lum.fading;
			info->light += o_spot->value * lum.shining * lum.fading;
			calc_color(&s_color, o_spot->color, o_spot->value, lum.fading);
		}
		spot = spot->next;
	}
	info->color = retrieve_col(s_color, damer(param, info, info->s_pos),
		   			get_shine(info));
}
