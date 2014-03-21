#include "raytracer.h"

double	norme(t_coord vect)
{
	return (sqrt(SQR(vect.x) + SQR(vect.y) + SQR(vect.z)));
}

double	dot_product(t_coord p1, t_coord p2)
{
	double	tmp;

	tmp = p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
	return (tmp);
}

t_coord	calc_vec(t_coord p1, t_coord p2)
{
	t_coord	n_p;

	n_p.x = p2.x - p1.x;
	n_p.y = p2.y - p1.y;
	n_p.z = p2.z - p1.z;
	return (n_p);
}

double	ft_abs(double nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int		point_cmp(t_coord p1, t_coord p2)
{
	if (ft_abs(p1.x - p2.x) > 0.0001)
		return (0);
	if (ft_abs(p1.y - p2.y) > 0.0001)
		return (0);
	if (ft_abs(p1.z - p2.z) > 0.0001)
		return (0);
	return (1);
}

t_coord	calc_v_reflex(t_coord v_dir, t_coord v_nor)
{
	double	tmp;
	t_coord	v_reflex;

	tmp = -2 * dot_product(v_dir, v_nor);
	v_reflex.x = v_dir.x + tmp * v_nor.x;
	v_reflex.y = v_dir.y + tmp * v_nor.y;
	v_reflex.z = v_dir.z + tmp * v_nor.z;
	return (v_reflex);
}

t_coord	turn_vect(t_coord vect)
{
	t_coord	n_vect;

	n_vect.x = -vect.x;
	n_vect.y = -vect.y;
	n_vect.z = -vect.z;
	return (n_vect);
}

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
	t_coord rv_lum;

	rv_lum = turn_vect(v_lum);
	v_reflex = calc_v_reflex(v_lum, v_nor);
	shining = pow(calc_fading(v_lum, v_reflex), 200);
	return (shining);
}

t_line	init_line(t_coord p1, t_coord p2)
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

t_info	init_light(t_info *info, t_spot *spot)
{
	t_info	light;

	light.r_line = init_line(info->r_pos, spot->coord);
	light.distance = -1;
	light.light = AMBL;
	light.color = NULL;
	return (light);
}

int 	*init_color(void)
{
	int *color;

//	ft_putstr("init_color -> ");
	color = (int *)j_malloc(sizeof(int) * 3);
	color[0] = 0;
	color[1] = 0;
	color[2] = 0;
//	ft_putstr("done\n");
	return (color);
}

void	calc_color(int **col, int *s_col, double s_light, double coef)
{
//	ft_putstr("calc_color -> ");
	(*col)[0] += s_light * s_col[0] * coef;
	(*col)[1] += s_light * s_col[1] * coef;
	(*col)[2] += s_light * s_col[2] * coef;
//	ft_putstr("done\n");
}

int 	*retrieve_col(int *col, int *obj_col, double coef)
{
	int 	*final_col;

//	ft_putstr("retrieve_col -> ");
	final_col = (int *)j_malloc(sizeof(int) * 3);
	final_col[0] = coef * (col[0] + obj_col[0]);
	final_col[1] = coef * (col[1] + obj_col[1]);
	final_col[2] = coef * (col[2] + obj_col[2]);
	if (final_col[0] > 255)
		final_col[0] = 255;
	if (final_col[1] > 255)
		final_col[1] = 255;
	if (final_col[2] > 255)
		final_col[2] = 255;
//	ft_putstr("done\n");
	return (final_col);
}

void	calc_light(t_param *param, t_info *info, t_list *spot)
{
	t_info	light;
	t_spot	*o_spot;
	double	fading;
	double	shining;
	int 	*s_color;

	if (info->distance < 0)
		return ;
	s_color = init_color();
	while (spot)
	{
		o_spot = (t_spot *)spot->content;
		light = init_light(info, o_spot);
		calc_intersection(param, &light);
		if (point_cmp(info->r_pos, light.r_pos) == 1)
		{
			fading = ft_abs(calc_fading(light.r_line.vec, info->vec_n));
			shining = ft_abs(calc_shining(info->vec_n, light.r_line.vec));
			info->light += o_spot->value * fading;
			info->light += o_spot->value * shining * fading;
			calc_color(&s_color, o_spot->color, o_spot->value, fading);
		}
		spot = spot->next;
	}
	info->color = retrieve_col(s_color, info->color, 0.5);
}
