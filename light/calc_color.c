/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:55:22 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/27 02:58:19 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

void	calc_color(int **col, int *s_col, double s_light, double coef)
{
	(*col)[0] += s_light * s_col[0] * coef;
	(*col)[1] += s_light * s_col[1] * coef;
	(*col)[2] += s_light * s_col[2] * coef;
}

int 	*retrieve_col(int *col, int *obj_col, double coef)
{
	int 	*final_col;

	final_col = (int *)j_malloc(sizeof(int) * 3);
	final_col[0] = coef * col[0] + obj_col[0] * (1 - coef);
	final_col[1] = coef * col[1] + obj_col[1] * (1 - coef);
	final_col[2] = coef * col[2] + obj_col[2] * (1 - coef);
	if (final_col[0] > 255)
		final_col[0] = 255;
	if (final_col[1] > 255)
		final_col[1] = 255;
	if (final_col[2] > 255)
		final_col[2] = 255;
	return (final_col);
}

int			final_color(int *color, double light)
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

int			calc_color_end(t_param *param, t_info *info)
{
	calc_reflex(param, info);
	calc_light(param, info, param->spot);
	return (final_color(info->color, info->light));
}

int		*convert_color(int color)
{
	int	*col;

	col = (int *)j_malloc(sizeof(int) * 3);
	col[0] = color % 256;
	color /= 256;
	col[1] = color % 256;
	color /= 256;
	col[2] = color % 256;
	return (col);
}
