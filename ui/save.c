
#include <time.h>
#include "raytracer.h"
#include "ui.h"

void		put_cam(t_param *param, int fd)
{
	ft_putendl_fd("//cam\n#cam pos_x pos_y pos_z rot_x rot_y rot_z", fd);
	ft_putnbr_fd(C_X, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(C_Y, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(C_Z, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(CR_X, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(CR_Y, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(CR_Z, fd);
	ft_putstr_fd("\n", fd);
}

static void lil_put_sphere(t_sphere *s, int fd)
{
	ft_putnbr_fd((int)s->pos.x, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)s->pos.y, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)s->pos.z, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(s->radius, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)s->lim_h_x, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)s->lim_b_x, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)s->lim_h_y, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)s->lim_b_y, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)s->lim_h_z, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)s->lim_b_z, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)s->mat.shine, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)s->mat.reflex, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)s->mat.med_in, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)s->mat.refrax, fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd("00FF00", fd);
	ft_putstr_fd("\n", fd);

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
	ft_putnbr_fd((int)s->coord.x, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)s->coord.y, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)s->coord.z, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(value, fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd("FFFFFF", fd);
	ft_putstr_fd("\n", fd);
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
	ft_putnbr_fd((int)p->pos.x, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)p->pos.y, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)p->pos.z, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)p->vec.x, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)p->vec.y, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)p->vec.z, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)p->mat.shine, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)p->mat.reflex, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)p->mat.med_in, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd((int)p->mat.refrax, fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd("FFFFFF", fd);
	ft_putstr_fd("\n", fd);
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
