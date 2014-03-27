/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clic.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 19:49:45 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/26 19:16:06 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include "ui.h"

void		clic_sphere(t_param *param, t_info *info)
{
	t_sphere   *s;

	s = info->obj;
	POS = &(s->pos);
	ROT = &(s->rot);
	RADIUS = &(s->radius);
}

void		clic_plane(t_param *param, t_info *info)
{
	t_plane		*p;

	p = info->obj;
	POS = &(p->pos);
	ROT = &(p->vec);
	RADIUS = NULL;
}

void		clic_cylinder(t_param *param, t_info *info)
{
	t_cylinder		*c;

	c = info->obj;
	POS = &(c->pos);
	ROT = &(c->rot);
	RADIUS = &(c->radius);
}

void		clic_cone(t_param *param, t_info *info)
{
	t_cone		*c;

	c = info->obj;
	POS = &(c->pos);
	ROT = &(c->rot);
	RADIUS = &(c->alpha);
}
