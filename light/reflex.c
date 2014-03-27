/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:46:35 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/27 02:46:38 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_line	init_line(t_line old_line, t_coord v_nor)
{
	t_line	line;

	line.vec = calc_v_reflex(old_line.vec, v_nor);
	line.pos.x = old_line.pos.x;
	line.pos.y = old_line.pos.y;
	line.pos.z = old_line.pos.z;
	return (line);
}

t_info	*new_vd(t_line old_line, t_coord v_nor)
{
	t_info	*reflex;

	reflex = (t_info *)j_malloc(sizeof(t_info));
	reflex->r_line = init_line(old_line, v_nor);
	reflex->distance = -1;
	reflex->light = AMBL;
	reflex->color = (int *)j_malloc(sizeof(int) * 3);
	reflex->obj_type = -1;
	return (reflex);
}

int 	*init_color(void)
{
	int *color;

	color = (int *)j_malloc(sizeof(int) * 3);
	color[0] = 0;
	color[1] = 0;
	color[2] = 0;
	return (color);
}

int		*recursive(t_param *param, t_info *info, int *color, int n)
{
	t_info	*ref;
	double	r_info;
	double	r_ref;

	ref = new_vd(info->r_line, info->vec_n);
	calc_intersection(param, ref);
	r_ref = get_reflex(ref);
	r_info = get_reflex(info);
	if (ref->distance != -1 && r_ref > 0 && n != 0)
		info->color = recursive(param, ref, color, n - 1);
	if (ref->distance == -1)
		return (init_color());
	calc_light(param, ref, param->spot);
	color = retrieve_col(damer(param, ref, ref->s_pos), info->color, r_info);
	return (color);
}

void	calc_reflex(t_param *param, t_info *info)
{
	int		*color;
	double	reflex;

	reflex = get_reflex(info);
	if (reflex <= 0.0001)
		return ;
	color = recursive(param, info, init_color(), 15);
	info->color = color;
}
