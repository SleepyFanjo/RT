/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:58:29 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/27 10:53:32 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

int			get_texture(t_info *info)
{
	if (info->obj_type == -1)
		return (0.0);
	if (info->obj_type == SPHERE)
		return (((t_sphere *)(info->obj))->mat.texture);
	if (info->obj_type == PLANE)
		return (((t_plane *)(info->obj))->mat.texture);
	if (info->obj_type == CYLINDER)
		return (((t_cylinder *)(info->obj))->mat.texture);
	if (info->obj_type == CONE)
		return (((t_cone *)(info->obj))->mat.texture);
	return (0);
}

int		*checker(t_coord point, t_info *info)
{
	double	tmp1;
	double	tmp2;
	int		*color;

	tmp1 = sin(F_PI / 70.0) * sin((F_PI / 70.0) * point.x);
	tmp2 = sin(F_PI / 70.0) * sin((F_PI / 70.0) * point.z);
	color = (int *)j_malloc(sizeof(int) * 3);
	if ((tmp1 >= 0 && tmp2 >= 0) || (tmp1 < 0 && tmp2 < 0))
		return (info->color);
	color[0] = 255;
	color[1] = 255;
	color[2] = 255;
	return (color);
}

t_coord	cross_product(t_coord v1, t_coord v2)
{
	t_coord	v_n;
	t_coord	new;
	double	norm_v1;
	double	norm_v2;

	v_n.x = 0;
	v_n.y = 0;
	v_n.z = 1;
	norm_v1 = norme(v1);
	norm_v2 = norme(v2);
	new.x = norm_v1 * norm_v2 * v_n.x;
	new.y = norm_v1 * norm_v2 * v_n.y;
	new.z = norm_v1 * norm_v2 * v_n.z;
	return (new);
}

int		*apply_text_sphere(t_coord point, t_textures tx)
{
	t_coord	v_n;
	t_coord	v_e;
	char	*color;
	t_map	t;

	v_n = init_vec_tx(0, 1, 0);
	v_e = init_vec_tx(1, 0, 0);
	t.new_point = normalize(point);
	t.phi = acos(-dot_product(v_n, t.new_point));
	t.v = t.phi / F_PI;
	t.theta = (acos(dot_product(t.new_point, v_e) / sin(t.phi))) / (2 * F_PI);
	if (dot_product(cross_product(v_n, v_e), point) > 0)
		t.u = t.theta;
	else
		t.u = 1 - t.theta;
	t.t_x = (int)(t.u * (double)tx.size_x);
	t.t_y = (int)(t.v * (double)tx.size_y);
	if ((t.t_x < 0 || t.t_x > tx.size_x) || (t.t_y < 0 || t.t_y > tx.size_y))
		return (init_color());
	color = (char *)j_malloc(sizeof(char) * 4);
	color[0] = (int)(tx.data[(t.t_y * tx.sizeline + t.t_x * (tx.bpp / 8))]);
	color[1] = (int)(tx.data[(t.t_y * tx.sizeline + t.t_x * (tx.bpp / 8) + 1)]);
	color[2] = (int)(tx.data[(t.t_y * tx.sizeline + t.t_x * (tx.bpp / 8) + 2)]);
	color[3] = 0;
	return (convert_color(*(int *)color));
}

int		*damer(t_param *param, t_info *info, t_coord point)
{
	int	tmp;

	if ((tmp = get_texture(info)) == DAMIER)
		return (checker(point, info));
	if (tmp == 0)
		return (info->color);
	if (get_texture(info) == TEXT_0)
		return (apply_text_sphere(point, T0));
	if (get_texture(info) == TEXT_1)
		return (apply_text_sphere(point, T1));
	if (get_texture(info) == TEXT_2)
		return (apply_text_sphere(point, T2));
	if (get_texture(info) == TEXT_3)
		return (apply_text_sphere(point, T3));
	if (get_texture(info) == TEXT_4)
		return (apply_text_sphere(point, T4));
	if (get_texture(info) == TEXT_5)
		return (apply_text_sphere(point, T5));
	if (get_texture(info) == TEXT_6)
		return (apply_text_sphere(point, T6));
	if (get_texture(info) == TEXT_7)
		return (apply_text_sphere(point, T7));
	if (get_texture(info) == TEXT_8)
		return (apply_text_sphere(point, T8));
	return (info->color);
}
