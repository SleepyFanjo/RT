/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 15:49:35 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 01:07:02 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "ui.h"

#include <stdio.h>

int		render(int keycode, t_param *param)
{
	if (keycode != 114)
		return (0);
	R = 1;
	return (1);
}

int		live(int keycode, t_param *param)
{
	if (keycode != 108)
		return (0);
	if (L)
		L = 0;
	else
		L = 1;
	return (1);
}

int		save(t_param *param)
{
	char		*name;
	int			fd;

	name = "save";
	if ((fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
		exit (0);
	put_cam(param, fd);
	put_sphere(param, fd);
	put_spot(param, fd);
	put_plane(param, fd);
	put_cone(param, fd);
	put_cylinder(param, fd);
	close(fd);
	return (1);
}

int		how_high(int keycode, t_param *param)
{
	if (keycode == PLUS)
	{
		POS->y += 25;
		return (1);
	}
	if (keycode == MINUS)
	{
		POS->y -= 25;
		return (1);
	}
	return (0);
}

int		roll(int keycode, t_param *param)
{
	if (keycode == NINE)
	{
		ROT->z += 5;
		if (ROT->z < 0)
			ROT->z += 360;
		if (ROT->z > 360)
			ROT->z -= 360;
		return (1);
	}
	if (keycode == SIX)
	{
		ROT->z -= 5;
		if (ROT->z < 0)
			ROT->z += 360;
		if (ROT->z > 360)
			ROT->z -= 360;
		return (1);
	}
	return (0);
}

int		wasd(int keycode, t_param *param)
{
	if (keycode == W)
	{
		POS->z += 25;
		return (1);
	}
	if (keycode == S)
	{
		POS->z -= 25;
		return (1);
	}
	if (keycode == D)
	{
		POS->x += 25;
		return (1);
	}
	if (keycode == A)
	{
		POS->x -= 25;
		return (1);
	}
	return (0);
}

int		arrows(int keycode, t_param *param)
{
	if (keycode == UP)
	{
		ROT->x -= 5;
		if (ROT->x < 0)
			ROT->x += 360;
		if (ROT->x > 360)
			ROT->x -= 360;
		return (1);
	}
	if (keycode == DOWN)
	{
		ROT->x += 5;
		if (ROT->x < 0)
			ROT->x += 360;
		if (ROT->x > 360)
			ROT->x -= 360;
		return (1);
	}
	if (keycode == RIGHT)
	{
		ROT->y -= 5;
		if (ROT->y < 0)
			ROT->y += 360;
		if (ROT->y > 360)
			ROT->y -= 360;
		return (1);
	}
	if (keycode == LEFT)
	{
		ROT->y += 5;
		if (ROT->y < 0)
			ROT->y += 360;
		if (ROT->y > 360)
			ROT->y -= 360;
		return (1);
	}
	return (0);
}

int		back_to_cam(int keycode, t_param *param)
{
	if (keycode != 118)
		return (0);
	POS = &(param->cam);
	ROT = &(param->rot_cam);
	RADIUS = NULL;
	return (1);
}

int		rad(int keycode, t_param *param)
{
	if (keycode == 45 && RADIUS != NULL && *(RADIUS) > 0)
	{
		//if cone alpha
		*(RADIUS) -= 15;
		return (1);
	}
	if (keycode == 61 && RADIUS != NULL)
	{
		//if cone alpah
		*(RADIUS) += 15;
		return (1);
	}
	return (0);
}

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

void		supp(t_param *param, int obj)
{
	t_list	*elem;

	if (obj == SPHERE)
	{
		elem = find_sphere(param, param->sphere);
		ft_lstdelone(&(param->sphere), elem);
	}
	if (obj == PLANE)
	{
		elem = find_plane(param, param->plane);
		ft_lstdelone(&(param->plane), elem);
	}
	if (obj == CYLINDER)
	{
		elem = find_cylinder(param, param->cylinder);
		ft_lstdelone(&(param->cylinder), elem);
	}
	if (obj == CONE)
	{
		elem = find_cone(param, param->cone);
		ft_lstdelone(&(param->cone), elem);
	}
}

int			del(int keycode, t_param *param)
{
	static int	(*sup_tab);

	if (keycode != DEL)
		return (0);
	if (FOCUS == SPHERE)
		supp(param, SPHERE);
	if (FOCUS == PLANE)
		supp(param, PLANE);
	if (FOCUS == CYLINDER)
		supp(param, CYLINDER);
	if (FOCUS == CONE)
		supp(param, CONE);
	FOCUS = -1;
	return (1);
}

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

int fd =open ("save", O_WRONLY | O_APPEND | O_CREAT, 0644);
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
	t_list	*elem;

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
