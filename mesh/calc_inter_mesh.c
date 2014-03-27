#include "raytracer.h"
#include "mesh_struct.h"

void	calc_inter_mesh(t_info *inf, t_list *lst_mesh)
{
	t_mesh		*mesh;

	printf("lst_mesh: %p\n", lst_mesh);
	while (lst_mesh != NULL)
	{
		mesh = lst_mesh->content;
		calc_inter_tri(mesh, inf);
		lst_mesh = lst_mesh->next;
	}
}
