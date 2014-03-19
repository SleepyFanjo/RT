#include "raytracer.h"

double	norme(t_coord vect)
{
	return (sqrt(SQR(vect.x) + SQR(vect.y) + SQR(vect.z)));
}

double	dot_product(t_coord p1, t_coord p2)
{
	double	tmp;

	tmp = p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
	tmp = tmp / (norme(p1) * norme(p2));
	return (tmp);
}

double	ft_abs(double nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int		point_cmp(t_coord p1, t_coord p2)
{
	if (ft_abs(p1.x - p2.x) > 0.01)
		return (0);
	if (ft_abs(p1.y - p2.y) > 0.01)
		return (0);
	if (ft_abs(p1.z - p2.z) > 0.01)
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

double	calc_shining(t_coord v_dir, t_coord v_nor, t_coord v_lum)
{
	double	shining;
	t_coord	v_reflex;

	v_reflex = calc_v_reflex(v_dir, v_nor);
	shining = pow(-dot_product(v_lum, v_reflex), 100);
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

void	calc_light(t_param *param, t_info *info, t_list *spot)
{
	t_info	light;
	t_spot	*o_spot;
	double	fading;
	double	shining;

	if (info->distance < 0)
		return ;
	while (spot)
	{
		o_spot = (t_spot *)spot->content;
		light = init_light(info, o_spot);
		calc_intersection(param, &light);
		if (point_cmp(info->r_pos, light.r_pos) == 1)
		{
			fading = ft_abs(dot_product(light.r_line.vec, info->vec_n));
			shining = ft_abs(calc_shining(info->r_line.vec, light.vec_n, light.r_line.vec));
			info->light += o_spot->value * fading;
			info->light += o_spot->value * shining;
		}
		spot = spot->next;
	}
}
