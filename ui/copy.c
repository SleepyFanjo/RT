/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 09:43:55 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 10:01:18 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "ui.h"

int			*cpy_col(int *col)
{
	int		*new;

	if (!(new = (int *)malloc(sizeof(int) * 3)))
		exit (0);
	new[0] = col[0];
	new[1] = col[1];
	new[2] = col[2];
	return (new);
}

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

int fd = open ("save", O_WRONLY | O_APPEND | O_CREAT, 0644);
l_printf("%q#on dup\n", fd);
	if ((new = (t_sphere *)malloc(sizeof(t_sphere))) == NULL)
		exit (0);
	while (l != NULL)
	{
		s = l->content;
l_printf("%q# X%d Y%d Z%d\n", fd, (int)s->pos.x, (int)s->pos.y, (int)s->pos.z);
		if (s->pos.x == POS->x && s->pos.y == POS->y
				&& s->pos.z == POS->z)
		{
			new = lil_dup_sphere(s, new);
			break ;
		}
		l = l->next;
	}
	calc_matrix((void *)s, SPHERE);
	ft_lstadd(&l, ft_lstnew(new, sizeof(t_sphere)));
}

int			copy(int keycode, t_param *param)
{
	if (keycode != C)
		return (0);
	if (FOCUS == SPHERE)
		dup_sphere(param, param->sphere);
/*	if (FOCUS == PLANE)
		supp(param, PLANE);
	if (FOCUS == CYLINDER)
		supp(param, CYLINDER);
	if (FOCUS == CONE)
		supp(param, CONE);*/
	return (1);

}
