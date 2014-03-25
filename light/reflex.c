#include "light.h"

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
	line.pos.x = old_line.pos.x;
	line.pos.y = old_line.pos.y;
	line.pos.z = old_line.pos.z;
	return (line);
}

t_info	*new_vd(t_line old_line, t_coord v_nor)
{
	t_info	*reflex;

	reflex = (t_info *)j_malloc(sizeof(t_info));
//	reflex->r_line = new_line(old_line, v_nor);
	reflex->r_line = init_line(old_line, v_nor);
	reflex->distance = -1;
	reflex->light = AMBL;
	reflex->color = (int *)j_malloc(sizeof(int) * 3);
	reflex->color = NULL;
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

void	calc_reflex_color(int **col, int *obj_col, double reflex)
{
	(*col)[0] = reflex * obj_col[0] + (1 - reflex) * (*col)[0];
	(*col)[1] = reflex * obj_col[1] + (1 - reflex) * (*col)[1];
	(*col)[2] = reflex * obj_col[2] + (1 - reflex) * (*col)[2];
}
/*
int		*rec_reflexion(t_param *param, t_info *info, int *color, double o_ref)
{
	static int	n = 10;
	double	reflex;

	info = new_vd(info->r_line, info->vec_n);
	calc_intersection(param, info);
	reflex = get_reflex(info);
	if (info->distance != -1)
	{
		calc_reflex_color(&color, info->color, o_ref);
	}
	else if (reflex == -1.0 || n == 0)
	{
		return (color);
	}
	n -= 1;
	return (reflexion(param, info, color, reflex));
}
*/

int		*reflexion(t_param *param, t_info *info)
{
	t_info *ref;

	ref = new_vd(info->r_line, info->vec_n);
	calc_intersection(param, ref);
	calc_light(param, ref, param->spot);
	if (ref->distance != -1)
		return (retrieve_col(damer(param, ref, ref->r_pos),
				   info->color, get_reflex(info)));
	return (init_color());
}
/*
int		*recursive(t_param *param, t_info *info, int *color, int n)
{
	t_info	*ref;
	double	reflex;

ft_putstr_fd("L\n", open("toto", O_WRONLY | O_CREAT | O_APPEND, 0644));
	ref = new_vd(info->r_line, info->vec_n);
	calc_intersection(param, ref);
	reflex = get_reflex(ref);
	if (ref->distance != -1)
	{
//		ref->color = reflexion(param, info);
		calc_light(param, ref, param->spot);
		color = retrieve_col(ref->color, info->color, reflex);
	}
	if (reflex == 0 || n == 0)
		return (color = retrieve_col(ref->color, info->color, reflex));
	return (recursive(param, ref, color, n - 1));
}
*/
int		*recursive(t_param *param, t_info *info, int *color, int n, int fd)
{
	t_info	*ref;
	double	r_info;
	double	r_ref;

//dprintf(fd, "round in recursivity\n");
	ref = new_vd(info->r_line, info->vec_n);
	calc_intersection(param, ref);
	r_ref = get_reflex(ref);
	r_info = get_reflex(info);
	if (ref->distance != -1 && r_ref > 0 && n != 0)
		info->color = recursive(param, ref, color, n - 1, fd);
	if (ref->distance == -1)
		return (init_color());
dprintf(fd, "i = %d, obj_type = %d - reflex = %f\n",n,  ref->obj_type, r_ref);
	calc_light(param, ref, param->spot);
	color = retrieve_col(damer(param, ref, ref->r_pos), info->color, r_info);
	return (color);
}

int		*cpy_color(int *src)
{
	int	*color;

	color = (int *)j_malloc(sizeof(int) * 3);
	color[0] = src[0];
	color[1] = src[1];
	color[2] = src[2];
	return (color);
}

void	calc_reflex(t_param *param, t_info *info)
{
	int		*color;
//	t_info	ref;
	double	reflex;
int fd;

fd = open("toto", O_WRONLY | O_CREAT | O_APPEND, 0644);
	reflex = get_reflex(info);
//dprintf(fd, "obj_type = %d - reflex = %e\n", info->obj_type, reflex);
	if (reflex <= 0.0001)
		return ;
//dprintf(fd, "obj_type = %d - reflex = %f\n", info->obj_type, reflex);
//	ref = init_reflex(info->r_line, info->vec_n);
	color = recursive(param, info, init_color(), 15, fd);
//	color = reflexion(param, info);
//	if (color[0] == 0 && color[1] == 0 && color[2] == 0)
//		color = info->color;
//	info->color = retrieve_col(color, info->color, reflex);
	info->color = color;
}
