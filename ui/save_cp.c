/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_cp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 09:19:24 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 10:19:18 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "ui.h"

static void lil_put_sphere(t_sphere *s, int fd)
{
	l_printf("%q%d %d %d ", fd, (int)s->pos.x, (int)s->pos.y, (int)s->pos.z);
	l_printf("%q%d %d %d %d %d ", fd, (int)s->rot.x, (int)s->rot.y
		, (int)s->rot.z, s->radius, s->is_limited);
	l_printf("%q%d %d %d %d %d %d ", fd, (int)s->lim_h_x, (int)s->lim_b_x
		, (int)s->lim_h_y, (int)s->lim_b_y, (int)s->lim_h_z, (int)s->lim_b_z);
	l_printf("%q%d %d %d %d ", fd, (int)(s->mat.shine * 100)
		, (int)(s->mat.reflex * 100), (int)(s->mat.med_in * 100)
		, (int)(s->mat.refrax * 100));
	l_printf("%q%d %d ", fd, (int)(s->mat.trans * 100), s->mat.texture);
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

static void lil_put_plane(t_plane *p, int fd)
{
	l_printf("%q%d %d %d ", fd, (int)p->pos.x, (int)p->pos.y, (int)p->pos.z);
	l_printf("%q%d %d %d ", fd, (int)p->vec.x, (int)p->vec.y, (int)p->vec.z);
	l_printf("%q%d %d %d %d ", fd, (int)(p->mat.shine * 100)
		, (int)(p->mat.reflex * 100), (int)(p->mat.med_in * 100)
		, (int)(p->mat.refrax * 100));
	l_printf("%q%d %d ", fd, (int)(p->mat.trans * 100), p->mat.texture);
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
