/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_sp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:11:27 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 14:34:02 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "ui.h"

t_sphere	*lil_dup_sphere(t_sphere *s, t_sphere *obj)
{
	obj->pos.x = s->pos.x;
	obj->pos.y = s->pos.y;
	obj->pos.z = s->pos.z;
	obj->rot.x = s->rot.x;
	obj->rot.y = s->rot.y;
	obj->rot.z = s->rot.z;
	obj->radius = s->radius;
	obj->is_limited = s->is_limited;
	obj->lim_h_x = s->lim_h_x;
	obj->lim_b_x = s->lim_b_x;
	obj->lim_h_y = s->lim_h_y;
	obj->lim_b_y = s->lim_b_y;
	obj->lim_h_z = s->lim_h_z;
	obj->lim_b_z = s->lim_b_z;
	obj->mat.shine = s->mat.shine;
	obj->mat.reflex = s->mat.reflex;
	obj->mat.med_in = s->mat.med_in;
	obj->mat.refrax = s->mat.refrax;
	obj->mat.trans = s->mat.trans;
	obj->mat.texture = s->mat.texture;
	obj->color = cpy_col(s->color);
	return (obj);
}

void		dup_sphere(t_param *param, t_list *l)
{
	t_sphere		*s;
	t_sphere		*new;

	if ((new = (t_sphere *)malloc(sizeof(t_sphere))) == NULL)
		exit (0);
	while (l != NULL)
	{
		s = l->content;
		if (s->pos.x == POS->x && s->pos.y == POS->y
				&& s->pos.z == POS->z)
		{
			new = lil_dup_sphere(s, new);
			break ;
		}
		l = l->next;
	}
	calc_matrix((void *)new, SPHERE);
	ft_lstadd(&l, ft_lstnew(new, sizeof(t_sphere)));
}

t_plane		*lil_dup_plane(t_plane *s, t_plane *obj)
{
	obj->pos.x = s->pos.x;
	obj->pos.y = s->pos.y;
	obj->pos.z = s->pos.z;
	obj->vec.x = s->vec.x;
	obj->vec.y = s->vec.y;
	obj->vec.z = s->vec.z;
	obj->mat.shine = s->mat.shine;
	obj->mat.reflex = s->mat.reflex;
	obj->mat.med_in = s->mat.med_in;
	obj->mat.refrax = s->mat.refrax;
	obj->mat.trans = s->mat.trans;
	obj->mat.texture = s->mat.texture;
	obj->color = cpy_col(s->color);
	return (obj);
}

void		dup_plane(t_param *param, t_list *l)
{
	t_plane		*s;
	t_plane		*new;

	if ((new = (t_plane *)malloc(sizeof(t_plane))) == NULL)
		exit (0);
	while (l != NULL)
	{
		s = l->content;
		if (s->pos.x == POS->x && s->pos.y == POS->y
				&& s->pos.z == POS->z)
		{
			new = lil_dup_plane(s, new);
			break ;
		}
		l = l->next;
	}
	calc_matrix((void *)new, PLANE);
	ft_lstadd(&l, ft_lstnew(new, sizeof(t_plane)));
}
