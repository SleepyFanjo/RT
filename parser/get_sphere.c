/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_get_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 15:47:13 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/22 15:11:50 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static void	set_sphere(t_sphere *obj, char **tab)
{
	obj->pos.x = ft_atoi(tab[0]);
	obj->pos.y = ft_atoi(tab[1]);
	obj->pos.z = ft_atoi(tab[2]);
	obj->radius = ft_atoi(tab[3]);
	obj->lim_h_x = ft_atoi(tab[4]);
	obj->lim_b_x = ft_atoi(tab[5]);
	obj->lim_h_y = ft_atoi(tab[6]);
	obj->lim_b_y = ft_atoi(tab[7]);
	obj->lim_h_z = ft_atoi(tab[8]);
	obj->lim_b_z = ft_atoi(tab[9]);
	obj->mat.shine = ft_atoi(tab[10]) / 100.0;
	obj->mat.reflex = ft_atoi(tab[11]) / 100.0;
	obj->mat.med_in = ft_atoi(tab[12]) / 100.0;
	obj->mat.refrax = ft_atoi(tab[13]) / 100.0;
}

int			get_sphere(t_obj *obj, char *line)
{
	char		**tab;
	int			i;
	t_sphere	*sphere;

	i = 0;
	if ((tab = ft_strsplit(line, ' ')) == NULL)
	{
		ft_printf("%rAllocation Fail: ");
		return (-1);
	}
	if (get_size_tab(tab) != 15)
	{
		ft_printf("%rThis line has no 15 param: ");
	}
	if (!test_tab(tab, 14))
		return (-1);
	if ((sphere = (t_sphere *)malloc(sizeof(t_sphere))) == NULL)
		ft_printf("%rAllocation fail: ");
	set_sphere(sphere, tab);
	sphere->color = get_color(tab[14]);
	if (sphere->color == NULL)
		return (-1);
	ft_lstadd(&(obj->sphere), ft_lstnew(sphere, sizeof(t_sphere)));
	return (0);
}
