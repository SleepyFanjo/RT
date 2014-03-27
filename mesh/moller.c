#include "raytracer.h"
#include "mesh_struct.h"

static int		free_return(void *p1, void *p2, int return_value)
{
	free(p1);
	free(p2);
	return (return_value);
}

static void		prequel_calc(t_edge *edge, t_triangle *v, t_vec *ve, t_ray *ray)
{
	v_sub(edge->edge1, v->vert1, v->vert0);
	v_sub(edge->edge2, v->vert2, v->vert0);
	v_cross(ve->pvec, ray->dir, edge->edge2);
}

int				inter_tri(t_triangle *vert, t_ray *ray, t_res_triangle *res)
{
	t_edge			*edge;
	t_vec			*vec;
	double			det;
	double			inv_det;

	vec = malloc(sizeof(t_vec));
	edge = malloc(sizeof(t_edge));
	prequel_calc(edge, vert, vec, ray);
	det = v_dot(edge->edge1, vec->pvec);
	if (det < EPSILON)
		return (free_return((void *)edge, (void *)vec, 0));
	v_sub(vec->tvec, ray->orig, vert->vert0);
	res->u = v_dot(vec->tvec, vec->pvec);
	if (res->u < 0.0 || res->u > det)
		return (free_return((void *)edge, (void *)vec, 0));
	v_cross(vec->qvec, vec->tvec, edge->edge1);
	res->v = v_dot(ray->dir, vec->qvec);
	if (res->v < 0.0 || res->u + res->v > det)
		return (free_return((void *)edge, (void *)vec, 0));
	res->t = v_dot(edge->edge2, vec->qvec);
	inv_det = 1.0 / det;
	res->t *= inv_det;
	res->u *= inv_det;
	res->v *= inv_det;
	return (free_return((void *)edge, (void *)vec, 1));
}
