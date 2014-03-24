#include "light.h"

void			get_textures(t_param *param, t_env e)
{
	T0.img = mlx_xpm_file_to_image(e.mlx, "./textures/0.xpm", &T0.size_x, &T0.size_y);
	T0.data = mlx_get_data_addr(T0.img, &T0.bpp, &T0.sizeline, &T0.endian);
	T1.img = mlx_xpm_file_to_image(e.mlx, "./textures/1.xpm", &T1.size_x, &T1.size_y);
	T1.data = mlx_get_data_addr(T1.img, &T1.bpp, &T1.sizeline, &T1.endian);
	T2.img = mlx_xpm_file_to_image(e.mlx, "./textures/2.xpm", &T2.size_x, &T2.size_y);
	T2.data = mlx_get_data_addr(T2.img, &T2.bpp, &T2.sizeline, &T2.endian);
	T3.img = mlx_xpm_file_to_image(e.mlx, "./textures/3.xpm", &T3.size_x, &T3.size_y);
	T3.data = mlx_get_data_addr(T3.img, &T3.bpp, &T3.sizeline, &T3.endian);
	T4.img = mlx_xpm_file_to_image(e.mlx, "./textures/4.xpm", &T4.size_x, &T4.size_y);
	T4.data = mlx_get_data_addr(T4.img, &T4.bpp, &T4.sizeline, &T4.endian);
	T5.img = mlx_xpm_file_to_image(e.mlx, "./textures/5.xpm", &T5.size_x, &T5.size_y);
	T5.data = mlx_get_data_addr(T5.img, &T5.bpp, &T5.sizeline, &T5.endian);
	T6.img = mlx_xpm_file_to_image(e.mlx, "./textures/6.xpm", &T6.size_x, &T6.size_y);
	T6.data = mlx_get_data_addr(T6.img, &T6.bpp, &T6.sizeline, &T6.endian);
	T7.img = mlx_xpm_file_to_image(e.mlx, "./textures/7.xpm", &T7.size_x, &T7.size_y);
	T7.data = mlx_get_data_addr(T7.img, &T7.bpp, &T7.sizeline, &T7.endian);
	T8.img = mlx_xpm_file_to_image(e.mlx, "./textures/8.xpm", &T8.size_x, &T8.size_y);
	T8.data = mlx_get_data_addr(T8.img, &T8.bpp, &T8.sizeline, &T8.endian);
}

int		*checker_1(t_coord point)
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

int		*checker_2(t_coord point)
{
	double	tmp1;
	double	tmp2;
	int		*color;

	tmp1 = sin(F_PI / 70.0) * sin((F_PI / 70.0) * point.y);
	tmp2 = sin(F_PI / 70.0) * sin((F_PI / 70.0) * point.z);
	color = (int *)j_malloc(sizeof(int) * 3);
	if ((tmp1 >= 0 && tmp2 >= 0) || (tmp1 < 0 && tmp2 < 0))
		return (init_color());
	color[0] = 255;
	color[1] = 255;
	color[2] = 255;
	return (color);
}

int		*checker_3(t_coord point)
{
	double	tmp1;
	double	tmp2;
	int		*color;

	tmp1 = sin(F_PI / 70.0) * sin((F_PI / 70.0) * point.x);
	tmp2 = sin(F_PI / 70.0) * sin((F_PI / 70.0) * point.y);
	color = (int *)j_malloc(sizeof(int) * 3);
	if ((tmp1 >= 0 && tmp2 >= 0) || (tmp1 < 0 && tmp2 < 0))
		return (init_color());
	color[0] = 255;
	color[1] = 255;
	color[2] = 255;
	return (color);
}

int		*checker(t_info *info, t_coord point)
{
	double	med;

	med = get_med(info);
	if (med <= 0.3)
		return (checker_1(point));
	else if (med >= 0.7)
		return (checker_3(point));
	else
		return (checker_2(point));
}

t_coord	get_polar(t_coord center, t_coord contact)
{
	t_coord polar;

	polar.x = contact.x - center.x;
	polar.y = contact.y - center.y;
	polar.z = contact.z - center.z;
	return (polar);
}

int		*apply_text_sphere(t_coord point, t_sphere *s, t_textures t)
{
	int		*color;
	int		t_x;
	int		t_y;
	double	tmp_x;
	double	tmp_y;
	t_coord	p;
	double	tmp1;
	double	tmp2;
	double	tmp3;
	static int i= 0;
	(void)point;
	(void)s;
	p = get_polar(s->pos, point);
	tmp1 = acos(p.z / s->radius);
	tmp2 = tmp1 / F_PI;
	tmp3 = tmp2 * t.size_x;
//	if (i<30)
//	{
//		printf("acos : %e, acos/PI : %e, acos/PI*X : %e\n", tmp1, tmp2, tmp3);
//		printf("p.x : %e, p.y : %e, p.z : %e\n", point.x, point.y, point.z);
//		printf("sizex : %d, sizey : %d\n", t.size_x, t.size_y);
//		printf("t_x : %d, t_y : %d\n", t_x, t_y);
//	}
	tmp_x = ((acos(p.z / s->radius) / F_PI));
	tmp_y = ((acos(p.x / (s->radius * sin(tmp_x * F_PI))) / (2 * F_PI)));
	t_x = (int)(tmp_x * t.size_x);
	t_y = (int)(tmp_y * t.size_y);
//	if (i<30)
//	{
//		printf("acos : %e, acos/PI : %e, acos/PI*X : %e\n", tmp1, tmp2, tmp3);
//		printf("p.x : %e, p.y : %e, p.z : %e\n", point.x, point.y, point.z);
//		printf("sizex : %d, sizey : %d\n", t.size_x, t.size_y);
//		printf("t_x : %d, t_y : %d\n", t_x, t_y);
//	}
//	printf("t_x : %d, t_y : %d\n", t_x, t_y);
	if ((t_x < 0 || t_x > t.size_x) || (t_y < 0 || t_y > t.size_y))
		return (init_color());
	color = (int *)j_malloc(sizeof(int) * 3);
	color[0] = (int)(t.data[(t_y * t.sizeline + t_x * (t.bpp / 8))]);
	color[1] = (int)(t.data[(t_y * t.sizeline + t_x * (t.bpp / 8)+ 1)]);
	color[2] = (int)(t.data[(t_y * t.sizeline + t_x * (t.bpp / 8)+ 2)]);
	i++;
	return (color);
}

int		*damer(t_param *param, t_info *info, t_coord point)
{
	int	tmp;

	if ((tmp = get_texture(info)) == DAMIER)
		return (checker(info, point));
	if (get_texture(info) == TEXT_1)
		return (apply_text_sphere(point, (t_sphere *)info->obj, T0));
	if (get_texture(info) == TEXT_2)
		return (apply_text_sphere(point, (t_sphere *)info->obj, T1));
	if (get_texture(info) == TEXT_3)
		return (apply_text_sphere(point, (t_sphere *)info->obj, T2));
	if (get_texture(info) == TEXT_4)
		return (apply_text_sphere(point, (t_sphere *)info->obj, T3));
	if (get_texture(info) == TEXT_5)
		return (apply_text_sphere(point, (t_sphere *)info->obj, T4));
	if (get_texture(info) == TEXT_6)
		return (apply_text_sphere(point, (t_sphere *)info->obj, T5));
	if (get_texture(info) == TEXT_7)
		return (apply_text_sphere(point, (t_sphere *)info->obj, T6));
	if (get_texture(info) == TEXT_8)
		return (apply_text_sphere(point, (t_sphere *)info->obj, T7));
//	if (get_texture(info) == TEXT_9)
//		return (apply_text_sphere(point, (t_sphere *)info->obj, T8));
	return (info->color);
}
