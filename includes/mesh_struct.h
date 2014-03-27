#ifndef MESH_STRUCT_H
# define MESH_STRUCT_H

# define EPSILON 0.000001

typedef struct	s_res_triangle
{
	double		u;
	double		t;
	double		v;
}				t_res_triangle;

typedef struct	s_ray
{
	double		orig[3];
	double		dir[3];
}				t_ray;

typedef struct	s_edge
{
	double		edge1[3];
	double		edge2[3];
}				t_edge;

typedef struct	s_vec
{
	double		tvec[3];
	double		pvec[3];
	double		qvec[3];
}				t_vec;

void		v_cross(double *dest, double *v1, double *v2);
double		v_dot(double *v1, double *v2);
void		v_sub(double *dest, double *v1, double *v2);
void	calc_inter_tri(t_mesh *mesh, t_info *inf);
int		inter_tri(t_triangle *vert, t_ray *ray, t_res_triangle *res);

#endif
