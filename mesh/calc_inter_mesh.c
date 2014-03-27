#include "raytracer.h"
#include "mesh_struct.h"

void	calc_inter_mesh(t_info *inf, t_list *lst_mesh)
{
	t_mesh		*mesh;

	while (lst_mesh != NULL)
	{
		mesh = (t_mesh *)lst_mesh->content;
		calc_inter_tri(mesh, inf);
		lst_mesh = lst_mesh->next;
	}
}
