/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 09:41:48 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 09:47:17 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "ui.h"

t_list		*find_sphere(t_param *param, t_list *l)
{
	t_sphere		*s;

	while (l != NULL)
	{
		s = l->content;
		if (s->pos.x == POS->x && s->pos.y == POS->y && s->pos.z == POS->z)
		{
			free(s->color);
			free(s->m);
			free(s->m_i);
			return (l);
		}
		l = l->next;
	}
	return (NULL);
}

t_list		*find_plane(t_param *param, t_list *l)
{
	t_plane		*s;

	while (l != NULL)
	{
		s = l->content;
		if (s->pos.x == POS->x && s->pos.y == POS->y && s->pos.z == POS->z)
		{
			free(s->color);
			free(s->m);
			free(s->m_i);
			return (l);
		}
		l = l->next;
	}
	return (NULL);
}

t_list		*find_cylinder(t_param *param, t_list *l)
{
	t_cylinder		*s;

	while (l != NULL)
	{
		s = l->content;
		if (s->pos.x == POS->x && s->pos.y == POS->y && s->pos.z == POS->z)
		{
			free(s->color);
			free(s->m);
			free(s->m_i);
			return (l);
		}
		l = l->next;
	}
	return (NULL);
}

t_list		*find_cone(t_param *param, t_list *l)
{
	t_cone		*s;

	while (l != NULL)
	{
		s = l->content;
		if (s->pos.x == POS->x && s->pos.y == POS->y && s->pos.z == POS->z)
		{
			free(s->color);
			free(s->m);
			free(s->m_i);
			return (l);
		}
		l = l->next;
	}
	return (NULL);
}
