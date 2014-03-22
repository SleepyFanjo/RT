#include "../light.h"

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

double	get_reflex(t_info *info)
{
//ft_putstr("get reflex -->");
	if (info->obj_type == -1)
		return (-1.0);
	if (info->obj_type == SPHERE)
		return (((t_sphere *)(info->obj))->mat.reflex);
	if (info->obj_type == PLANE)
		return (((t_plane *)(info->obj))->mat.reflex);
	if (info->obj_type == CYLINDER)
		return (((t_cylinder *)(info->obj))->mat.reflex);
	if (info->obj_type == CONE)
		return (((t_cone *)(info->obj))->mat.reflex);
	return (-1.0);
}

t_coord	normalize(t_coord vec)
{
	t_coord	n_vec;
	double	norm;

	norm = norme(vec);
	n_vec.x = vec.x / norm;
	n_vec.y = vec.y / norm;
	n_vec.z = vec.z / norm;
	return (n_vec);
}

t_coord	calc_v_reflex(t_coord ov_dir, t_coord ov_nor)
{
	double	tmp;
	t_coord	v_reflex;
	t_coord	v_dir;
	t_coord	v_nor;

	v_dir = normalize(ov_dir);
	v_nor = normalize(ov_nor);
	tmp = -2 * dot_product(v_dir, v_nor);
	v_reflex.x = v_dir.x + tmp * v_nor.x;
	v_reflex.y = v_dir.y + tmp * v_nor.y;
	v_reflex.z = v_dir.z + tmp * v_nor.z;
	return (v_reflex);
}

t_line	init_line(t_line old_line, t_coord v_nor)
{
	t_line	line;

	line.vec = calc_v_reflex(old_line.vec, v_nor);
	line.pos.x = old_line.pos.x * 1.1;
	line.pos.y = old_line.pos.y * 1.1;
	line.pos.z = old_line.pos.z * 1.1;
	return (line);
}

t_info	init_reflex(t_line old_line, t_coord v_nor)
{
	t_info	reflex;

//ft_putstr("init reflex -->");
	reflex.r_line = init_line(old_line, v_nor);
	reflex.distance = -1;
	reflex.light = AMBL;
	reflex.color = NULL;
	reflex.obj_type = -1;
//ft_putstr("done\n");
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

int		*reflexion(t_param *param, t_info *info)
{
	t_info	ref;
	double	reflex;

	reflex = get_reflex(info);
//ft_putstr("done\n");
	if (reflex == 0.0)
		return (info->color);
	if (reflex == -1.0)
		return (init_color());
//	printf("reflex = %f\n", reflex);
	ref = init_reflex(info->r_line, info->vec_n);
	calc_intersection(param, &ref);
//	ft_putstr("calc_inter\n");
	return (reflexion(param, &ref));
}

void	calc_reflex(t_param *param, t_info *info)
{
	int		*color;
	double	reflex;
	static	int i = 0;

//ft_putstr("frst calc reflex\n");
	reflex = get_reflex(info);
	if (i < 10)
		printf("   c[0] = %d, c[1] = %d, c[2] = %d\n", info->color[0], info->color[1], info->color[2]);
	if (reflex == -1.0 || reflex == 0.0)
		return ;
	color = init_color();
	color = reflexion(param, info);
//	printf("color %p, info %p\n", color, info->color);
//ft_putstr("Ldone\n");
//	printf("reflex = %f\n", reflex);
	if (i < 10)
		printf("=> c[0] = %d, c[1] = %d, c[2] = %d\n", info->color[0], info->color[1], info->color[2]);
	info->color[0] = reflex * color[0] + info->color[0] * (1 - reflex);
	info->color[1] = reflex * color[1] + info->color[1] * (1 - reflex);
	info->color[2] = reflex * color[2] + info->color[2] * (1 - reflex);
//	printf("c[0] = %d, c[1] = %d, c[2] = %d\n", info->color[0], info->color[1], info->color[2]);
	fflush(0);
	i++;
//ft_putstr(" done\n");
}
