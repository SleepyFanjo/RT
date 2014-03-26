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

int		*checker(t_coord point)
{
	double	tmp1;
	double	tmp2;
	int		*color;

	tmp1 = sin(F_PI / 70.0) * sin((F_PI / 70.0) * point.x);
	tmp2 = sin(F_PI / 70.0) * sin((F_PI / 70.0) * point.z);
	color = (int *)j_malloc(sizeof(int) * 3);
	if ((tmp1 >= 0 && tmp2 >= 0) || (tmp1 < 0 && tmp2 < 0))
		return (init_color());
	color[0] = 255;
	color[1] = 255;
	color[2] = 255;
	return (color);
}

t_coord	get_polar(t_coord center, t_coord contact)
{
	t_coord polar;

	polar.x = contact.x - center.x;
	polar.y = contact.y - center.y;
	polar.z = contact.z - center.z;
	return (polar);
}
/*
int		*apply_text_sphere(t_coord point, t_sphere *s, t_textures t)
{
	int		*color;
	int		t_x;
	int		t_y;
	double	tmp_x;
	double	tmp_y;
	t_coord	p;

	p = get_polar(s->pos, point);
	tmp_x = ((acos(p.z / s->radius) / F_PI));
	tmp_y = ((acos(p.x / (s->radius * sin(tmp_x * F_PI))) / (2 * F_PI)));
	t_x = (int)(tmp_x * t.size_x);
	t_y = (int)(tmp_y * t.size_y);
	ft_putnbr(t_y);
	ft_putchar('-');
	if ((t_x < 0 || t_x > t.size_x) || (t_y < 0 || t_y > t.size_y))
		return (init_color());
	color = (int *)j_malloc(sizeof(int) * 3);
	color[0] = (int)(t.data[(t_y * t.sizeline + t_x * (t.bpp / 8))]);
	color[1] = (int)(t.data[(t_y * t.sizeline + t_x * (t.bpp / 8) + 1)]);
	color[2] = (int)(t.data[(t_y * t.sizeline + t_x * (t.bpp / 8) + 2)]);
	return (color);
}
*/
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

int		*get_coolor(int color)
{
	int	*colr;

	colr = (int *)j_malloc(sizeof(int) * 3);
	colr[0] = color % 256;
	color /= 256;
	colr[1] = color % 256;
	color /= 256;
	colr[2] = color % 256;
	return (colr);
}

int		*apply_text_sphere(t_coord point, t_sphere *s, t_textures t)
{
	t_coord	v_n;
	t_coord	v_e;
	t_coord new_point;
	double	phi;
	double	theta;
	t_map	text;
	int		t_x;
	int		t_y;
	char	*color;

	v_n.x = 0;
	v_n.y = 1;
	v_n.z = 0;
	v_e.x = 1;
	v_e.y = 0;
	v_e.z = 0;
	new_point = normalize(point);
	phi = acos(-dot_product(v_n, new_point));
	printf("phi : %f\n", phi);
	text.v = phi / F_PI;
	theta = (acos(dot_product(new_point, v_e) / sin(phi))) / (2 * F_PI);
	printf("theta : %f\n", theta);
	if (dot_product(cross_product(v_n, v_e), point) > 0)
		text.u = theta;
	else
		text.u = 1 - theta;
	t_x = (int)(text.u * (double)t.size_x);
	t_y = (int)(text.v * (double)t.size_y);
	if ((t_x < 0 || t_x > t.size_x) || (t_y < 0 || t_y > t.size_y))
	{
//		printf("t_x : %d, t_y : %d\n", t_x, t_y);
//		printf("text_u : %e, text_v : %e\n", text.u, text.v);
//		printf("size_x : %d, size_y : %d\n", t.size_x, t.size_y);
		fflush(0);
		return (init_color());
	}
	color = (char *)j_malloc(sizeof(char) * 4);
	color[0] = (int)(t.data[(t_y * t.sizeline + t_x * (t.bpp / 8))]);
	color[1] = (int)(t.data[(t_y * t.sizeline + t_x * (t.bpp / 8) + 1)]);
	color[2] = (int)(t.data[(t_y * t.sizeline + t_x * (t.bpp / 8) + 2)]);
	color[3] = 0;
	return (get_coolor(*(int *)color));
}

int		*damer(t_param *param, t_info *info, t_coord point)
{
	int	tmp;

	if ((tmp = get_texture(info)) == DAMIER)
		return (checker(point));
	if (tmp == 0)
		return (info->color);
	if (get_texture(info) == TEXT_0)
		return (apply_text_sphere(info->r_pos, (t_sphere *)info->obj, T0));
	if (get_texture(info) == TEXT_1)
		return (apply_text_sphere(info->r_pos, (t_sphere *)info->obj, T1));
	if (get_texture(info) == TEXT_2)
		return (apply_text_sphere(info->r_pos, (t_sphere *)info->obj, T2));
	if (get_texture(info) == TEXT_3)
		return (apply_text_sphere(info->s_pos, (t_sphere *)info->obj, T3));
	if (get_texture(info) == TEXT_4)
		return (apply_text_sphere(point, (t_sphere *)info->obj, T4));
	if (get_texture(info) == TEXT_5)
		return (apply_text_sphere(info->vec_n, (t_sphere *)info->obj, T5));
	if (get_texture(info) == TEXT_6)
		return (apply_text_sphere(point, (t_sphere *)info->obj, T6));
	if (get_texture(info) == TEXT_7)
		return (apply_text_sphere(point, (t_sphere *)info->obj, T7));
	if (get_texture(info) == TEXT_8)
		return (apply_text_sphere(info->s_pos, (t_sphere *)info->obj, T8));
	return (info->color);
}
