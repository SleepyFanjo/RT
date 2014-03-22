#include "../raytracer.h"

static void	*free_spot(void *data)
{
	t_spot	*spot;

	spot = (t_spot *)data;
	free(spot->color);
	free(spot);
	return (NULL);
}

static void	*free_sphere(void *data)
{
	t_sphere	*obj;

	obj = (t_sphere *)data;
	free(obj->color);
	free(obj);
	return (NULL);
}

static void	*free_plane(void *data)
{
	t_plane		*obj;

	obj = (t_plane *)data;
	free(obj->color);
	free(obj);
	return (NULL);
}

static void	*free_cylinder(void *data)
{
	t_cylinder	*obj;

	obj = (t_cylinder *)data;
	free(obj->color);
	free(obj);
	return (NULL);
}

static void	*free_cone(void *data)
{
	t_cone		*obj;

	obj = (t_cone *)data;
	free(obj->color);
	free(obj);
	return (NULL);
}

void		free_obj_lst(t_param *p)
{
	ft_lstiter(p->spot, free_spot);
	ft_lstiter(p->sphere, free_sphere);
	ft_lstiter(p->cylinder, free_cylinder);
	ft_lstiter(p->cone, free_cone);
	ft_lstiter(p->plane, free_plane);
	ft_lstdel(&(p->spot), p->spot);
	ft_lstdel(&(p->sphere), p->sphere);
	ft_lstdel(&(p->cylinder), p->cylinder);
	ft_lstdel(&(p->cone), p->cone);
	ft_lstdel(&(p->plane), p->plane);
}
