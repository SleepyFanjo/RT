#include "raytracer.h"

void	calc_inter_mesh(t_info *inf, t_param *p)
{
	t_list		*lst_mesh;
	t_mesh		*mesh;

	lst_mesh = p->mesh;
	while (lst_mesh != NULL)
	{
		mesh = lst_mesh->content;
		calc_inter_tri(mesh, inf);
		lst_mesh = lst_mesh->next;
	}
}
