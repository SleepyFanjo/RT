/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 17:29:34 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 16:07:10 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static void	set_cylinder(t_cylinder *cylinder, char **tab)
{
	cylinder->pos.x = ft_atoi(tab[0]);
	cylinder->pos.y = ft_atoi(tab[1]);
	cylinder->pos.z = ft_atoi(tab[2]);
	cylinder->rot.x = ft_atoi(tab[3]);
	cylinder->rot.y = ft_atoi(tab[4]);
	cylinder->rot.z = ft_atoi(tab[5]);
	cylinder->radius = ft_atoi(tab[6]);
	cylinder->is_limited = ft_atoi(tab[7]);
	cylinder->lim_h = ft_atoi(tab[8]);
	cylinder->lim_b = ft_atoi(tab[9]);
	cylinder->mat.shine = ft_atoi(tab[10]) / 100.0;
	cylinder->mat.reflex = ft_atoi(tab[11]) / 100.0;
	cylinder->mat.med_in = ft_atoi(tab[12]) / 100.0;
	cylinder->mat.refrax = ft_atoi(tab[13]) / 100.0;
	cylinder->mat.trans = ft_atoi(tab[14]) / 100.0;
	cylinder->mat.texture = ft_atoi(tab[15]);
	calc_matrix((void *)cylinder, CYLINDER);
}

int			get_cylinder(t_obj *obj, char *line)
{
	char		**tab;
	t_cylinder	*cylinder;

	if ((tab = ft_strsplit(line, ' ')) == NULL)
	{
		ft_printf("%rAllocation Fail\n");
		return (-1);
	}
	if (get_size_tab(tab) != 17)
	{
		ft_printf("%rCylinder has no 17 param");
		return (-1);
	}
	if (!test_tab(tab, 16))
		return (-1);
	if ((cylinder = (t_cylinder *)malloc(sizeof(t_cylinder))) == NULL)
	{
		ft_printf("%rAllocation Fail\n");
		return (-1);
	}
	set_cylinder(cylinder, tab);
	if ((cylinder->color = get_color(tab[16])) == NULL)
		return (-1);
	ft_lstadd(&(obj->cylinder), ft_lstnew(cylinder, sizeof(t_cylinder)));
	return (0);
}
