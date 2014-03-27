/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 09:39:17 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 10:49:21 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "ui.h"

int		rad(int keycode, t_param *param)
{
	if (keycode == 45 && RADIUS != NULL && *(RADIUS) > 15)
	{
		*(RADIUS) -= 15;
		return (1);
	}
	if (keycode == 61 && RADIUS != NULL)
	{
		*(RADIUS) += 15;
		return (1);
	}
	return (0);
}

static void		supp(t_param *param, int obj)
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
