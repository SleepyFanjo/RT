/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:20:29 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 15:20:41 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static void	set_sphere(t_sphere *obj, char **tab)
{
	obj->pos.x = ft_atoi(tab[0]);
	obj->pos.y = ft_atoi(tab[1]);
	obj->pos.z = ft_atoi(tab[2]);
	obj->rot.x = ft_atoi(tab[3]);
	obj->rot.y = ft_atoi(tab[4]);
	obj->rot.z = ft_atoi(tab[5]);
	obj->radius = ft_atoi(tab[6]);
	obj->is_limited = ft_atoi(tab[7]);
	obj->lim_h_x = ft_atoi(tab[8]);
	obj->lim_b_x = ft_atoi(tab[9]);
	obj->lim_h_y = ft_atoi(tab[10]);
	obj->lim_b_y = ft_atoi(tab[11]);
	obj->lim_h_z = ft_atoi(tab[12]);
	obj->lim_b_z = ft_atoi(tab[13]);
	obj->mat.shine = ft_atoi(tab[14]) / 100.0;
	obj->mat.reflex = ft_atoi(tab[15]) / 100.0;
	obj->mat.med_in = ft_atoi(tab[16]) / 100.0;
	obj->mat.refrax = ft_atoi(tab[17]) / 100.0;
	obj->mat.trans = ft_atoi(tab[18]) / 100.0;
	obj->mat.texture = ft_atoi(tab[19]);
}

int			get_sphere(t_obj *obj, char *line)
{
	char		**tab;
	t_sphere	*sphere;

	if ((tab = ft_strsplit(line, ' ')) == NULL)
	{
		ft_printf("%rAllocation Fail: ");
		return (-1);
	}
	if (get_size_tab(tab) != 21)
	{
		ft_printf("%rThis line has no 21 param: ");
		return (-1);
	}
	if (!test_tab(tab, 20))
		return (-1);
	if ((sphere = (t_sphere *)malloc(sizeof(t_sphere))) == NULL)
		ft_printf("%rAllocation fail: ");
	set_sphere(sphere, tab);
	sphere->color = get_color(tab[20]);
	if (sphere->color == NULL)
		return (-1);
	calc_matrix((void *)sphere, SPHERE);
	ft_lstadd(&(obj->sphere), ft_lstnew(sphere, sizeof(t_sphere)));
	return (0);
}
