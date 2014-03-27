/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_cc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 09:12:58 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 10:19:00 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "ui.h"

static void lil_put_cylinder(t_cylinder *s, int fd)
{
	l_printf("%q%d %d %d ", fd, (int)s->pos.x, (int)s->pos.y, (int)s->pos.z);
	l_printf("%q%d %d %d %d %d ", fd, (int)s->rot.x, (int)s->rot.y
		, (int)s->rot.z, s->radius, s->is_limited);
	l_printf("%q%d %d  ", fd, (int)s->lim_h, (int)s->lim_b);
	l_printf("%q%d %d %d %d ", fd, (int)(s->mat.shine * 100)
		, (int)(s->mat.reflex * 100), (int)(s->mat.med_in * 100)
		, (int)(s->mat.refrax * 100));
	l_printf("%q%d %d ", fd, (int)(s->mat.trans * 100), s->mat.texture);
	l_printf("%q%X%X%X\n", fd, s->color[2], s->color[1], s->color[0]);
}

void		put_cylinder(t_param *param, int fd)
{
	t_cylinder		*s;
	t_list			*list;

	list = param->cylinder;
	ft_putendl_fd("//cylinder", fd);
	while (list != NULL)
	{
		s = list->content;
		lil_put_cylinder(s, fd);
		list = list->next;
	}
}

static void lil_put_cone(t_cone *s, int fd)
{
	l_printf("%q%d %d %d ", fd, (int)s->pos.x, (int)s->pos.y, (int)s->pos.z);
	l_printf("%q%d %d %d %d %d ", fd, (int)s->rot.x, (int)s->rot.y
		, (int)s->rot.z, s->alpha, s->is_limited);
	l_printf("%q%d %d  ", fd, (int)s->lim_h, (int)s->lim_b);
	l_printf("%q%d %d %d %d ", fd, (int)(s->mat.shine * 100)
		, (int)(s->mat.reflex * 100), (int)(s->mat.med_in * 100)
		, (int)(s->mat.refrax * 100));
	l_printf("%q%d %d ", fd, (int)(s->mat.trans * 100), s->mat.texture);
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
