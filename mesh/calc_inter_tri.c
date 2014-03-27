#include "raytracer.h"
#include "mesh_struct.h"

static void		coord_to_double(double *dest, t_coord *src)
{
	dest[0] = src->x;
	dest[1] = src->y;
	dest[2] = src->z;
}

void	calc_inter_tri(t_mesh *mesh, t_info *inf)
{
	t_triangle		**tri;
	t_res_triangle	res;
	int				i;
	t_ray			ray;

	i = 0;
	tri = mesh->tri;
	coord_to_double(ray.orig, &(inf->r_line.pos));
	coord_to_double(ray.dir , &(inf->r_line.vec));
	while (tri[i] != NULL)
	{
		if (inter_tri(tri[i], &ray, &res))
		{
			if (inf->distance > res.t)
			{
				inf->distance = res.t;
				inf->obj_type = MESH;
				inf->vec_n.x = tri[i]->vecn[0];
				inf->vec_n.y = tri[i]->vecn[1];
				inf->vec_n.z = tri[i]->vecn[2];
				inf->color = j_malloc(sizeof(int) * 3);
				inf->color[0] = 255;
				inf->color[1] = 0;
				inf->color[2] = 0;
			}
		}
		i++;
	}
}
