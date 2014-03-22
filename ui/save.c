
#include <time.h>
#include "raytracer.h"
#include "ui.h"

void		put_cam(t_param *param, int fd)
{
	ft_putendl_fd("//cam\n#cam pos_x pos_y pos_z rot_x rot_y rot_z", fd);
	l_printf("%q%d %d %d %d %d %d\n", fd, (int)C_X, (int)C_Y, (int)C_Z
			, (int)CR_X, (int)CR_Y, (int)CR_Z);
}

static void lil_put_sphere(t_sphere *s, int fd)
{
	l_printf("%q%d %d %d %d ",fd, (int)s->pos.x, (int)s->pos.y, (int)s->pos.z
		, s->radius);
	l_printf("%q%d %d %d %d %d %d ",fd, (int)s->lim_h_x, (int)s->lim_b_x
		, (int)s->lim_h_y, (int)s->lim_b_y, (int)s->lim_h_z, (int)s->lim_b_z);
	l_printf("%q%d %d %d %d ",fd, (int)(s->mat.shine * 100)
			, (int)(s->mat.reflex * 100), (int)(s->mat.med_in * 100)
			, (int)(s->mat.refrax * 100));
	l_printf("%q%X%X%X\n", fd, s->color[2], s->color[1], s->color[0]);
}

void		put_sphere(t_param *param, int fd)
{
	t_sphere		*s;
	t_list			*list;

	list = param->sphere;
	ft_putendl_fd("//sphere", fd);
	while (list != NULL)
	{
		s = list->content;
		lil_put_sphere(s, fd);
		list = list->next;
	}
}

static void lil_put_spot(t_spot *s, int fd)
{
	int		value;

	value = (int)(s->value * 1000);
	l_printf("%q%d %d %d %d ",fd, (int)s->coord.x, (int)s->coord.y
			, (int)s->coord.z, value);
	l_printf("%q%X%X%X\n", fd, s->color[2], s->color[1], s->color[0]);
}

void		put_spot(t_param *param, int fd)
{
	t_spot		*s;
	t_list		*list;

	list = param->spot;
	ft_putendl_fd("//spot", fd);
	while (list != NULL)
	{
		s = list->content;
		lil_put_spot(s, fd);
		list = list->next;
	}
}

static void lil_put_plane(t_plane *p, int fd)
{
	l_printf("%q%d %d %d ",fd, (int)p->pos.x, (int)p->pos.y, (int)p->pos.z);
	l_printf("%q%d %d %d ",fd, (int)p->vec.x, (int)p->vec.y, (int)p->vec.z);
	l_printf("%q%d %d %d %d ",fd, (int)(p->mat.shine * 100)
			, (int)(p->mat.reflex * 100), (int)(p->mat.med_in * 100)
			, (int)(p->mat.refrax * 100));
	l_printf("%q%X%X%X\n", fd, p->color[2], p->color[1], p->color[0]);
}

void		put_plane(t_param *param, int fd)
{
	t_plane		*p;
	t_list		*list;

	list = param->plane;
	ft_putendl_fd("//plane", fd);
	while (list != NULL)
	{
		p = list->content;
		lil_put_plane(p, fd);
		list = list->next;
	}
}

static void lil_put_cone(t_cone *s, int fd)
{
	l_printf("%q%d %d %d ",fd, (int)s->pos.x, (int)s->pos.y, (int)s->pos.z);
	l_printf("%q%d %d %d %d ",fd, (int)s->rot.x, (int)s->rot.y, (int)s->rot.z
			, s->alpha);
	l_printf("%q%d %d %d %d ",fd, (int)(s->mat.shine * 100)
			, (int)(s->mat.reflex * 100), (int)(s->mat.med_in * 100)
			, (int)(s->mat.refrax * 100));
	l_printf("%q%X%X%X\n", fd, s->color[2], s->color[1], s->color[0]);
}

void		put_cone(t_param *param, int fd)
{
	t_cone			*s;
	t_list			*list;

	list = param->cone;
	ft_putendl_fd("//cone", fd);
	while (list != NULL)
	{
		s = list->content;
		lil_put_cone(s, fd);
		list = list->next;
	}
}

static void lil_put_cylinder(t_cylinder *s, int fd)
{
	l_printf("%q%d %d %d ",fd, (int)s->pos.x, (int)s->pos.y, (int)s->pos.z);
	l_printf("%q%d %d %d %d ",fd, (int)s->rot.x, (int)s->rot.y, (int)s->rot.z
		, s->radius);
	l_printf("%q%d %d %d %d ",fd, (int)(s->mat.shine * 100)
			, (int)(s->mat.reflex * 100), (int)(s->mat.med_in * 100)
			, (int)(s->mat.refrax * 100));
	l_printf("%q%X%X%X\n", fd, s->color[2], s->color[1], s->color[0]);
}

void		put_cylinder(t_param *param, int fd)
{
	t_cylinder		*s;
	t_list			*list;

	list = param->cylinder;
	ft_putendl_fd("//sphere", fd);
	while (list != NULL)
	{
		s = list->content;
		lil_put_cylinder(s, fd);
		list = list->next;
	}
}
