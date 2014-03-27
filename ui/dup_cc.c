/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_cc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:22:52 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 14:33:42 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "ui.h"

t_cone		*lil_dup_cone(t_cone *s, t_cone *obj)
{
	obj->pos.x = s->pos.x;
	obj->pos.y = s->pos.y;
	obj->pos.z = s->pos.z;
	obj->rot.x = s->rot.x;
	obj->rot.y = s->rot.y;
	obj->rot.z = s->rot.z;
	obj->alpha = s->alpha;
	obj->is_limited = s->is_limited;
	obj->lim_h = s->lim_h;
	obj->lim_b = s->lim_b;
	obj->mat.shine = s->mat.shine;
	obj->mat.reflex = s->mat.reflex;
	obj->mat.med_in = s->mat.med_in;
	obj->mat.refrax = s->mat.refrax;
	obj->mat.trans = s->mat.trans;
	obj->mat.texture = s->mat.texture;
	obj->color = cpy_col(s->color);
	return (obj);
}

void		dup_cone(t_param *param, t_list *l)
{
	t_cone		*s;
	t_cone		*new;

	if ((new = (t_cone *)malloc(sizeof(t_cone))) == NULL)
		exit (0);
	while (l != NULL)
	{
		s = l->content;
		if (s->pos.x == POS->x && s->pos.y == POS->y
				&& s->pos.z == POS->z)
		{
			new = lil_dup_cone(s, new);
			break ;
		}
		l = l->next;
	}
	calc_matrix((void *)new, CONE);
	ft_lstadd(&l, ft_lstnew(new, sizeof(t_sphere)));
}

t_cylinder	*lil_dup_cylinder(t_cylinder *s, t_cylinder *obj)
{
	obj->pos.x = s->pos.x;
	obj->pos.y = s->pos.y;
	obj->pos.z = s->pos.z;
	obj->rot.x = s->rot.x;
	obj->rot.y = s->rot.y;
	obj->rot.z = s->rot.z;
	obj->radius = s->radius;
	obj->is_limited = s->is_limited;
	obj->lim_h = s->lim_h;
	obj->lim_b = s->lim_b;
	obj->mat.shine = s->mat.shine;
	obj->mat.reflex = s->mat.reflex;
	obj->mat.med_in = s->mat.med_in;
	obj->mat.refrax = s->mat.refrax;
	obj->mat.trans = s->mat.trans;
	obj->mat.texture = s->mat.texture;
	obj->color = cpy_col(s->color);
	return (obj);
}

void		dup_cylinder(t_param *param, t_list *l)
{
	t_cylinder		*s;
	t_cylinder		*new;

	if ((new = (t_cylinder *)malloc(sizeof(t_cylinder))) == NULL)
		exit (0);
	while (l != NULL)
	{
		s = l->content;
		if (s->pos.x == POS->x && s->pos.y == POS->y
				&& s->pos.z == POS->z)
		{
			new = lil_dup_cylinder(s, new);
			break ;
		}
		l = l->next;
	}
	calc_matrix((void *)new, CYLINDER);
	ft_lstadd(&l, ft_lstnew(new, sizeof(t_cylinder)));
}
