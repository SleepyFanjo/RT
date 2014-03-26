/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 17:29:34 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/26 18:32:10 by vwatrelo         ###   ########.fr       */
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
	cylinder->mat.shine = ft_atoi(tab[7]) / 100.0;
	cylinder->mat.reflex = ft_atoi(tab[8]) / 100.0;
	cylinder->mat.med_in = ft_atoi(tab[9]) / 100.0;
	cylinder->mat.refrax = ft_atoi(tab[10]) / 100.0;
	cylinder->mat.trans = ft_atoi(tab[11]) / 100.0;
	cylinder->mat.texture = ft_atoi(tab[12]);
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
	if (get_size_tab(tab) != 14)
	{
		ft_printf("%rCylinder has no 14 param");
		return (-1);
	}
	if (!test_tab(tab, 13))
		return (-1);
	if ((cylinder = (t_cylinder *)malloc(sizeof(t_cylinder))) == NULL)
	{
		ft_printf("%rAllocation Fail\n");
		return (-1);
	}
	set_cylinder(cylinder, tab);
	if ((cylinder->color = get_color(tab[13])) == NULL)
		return (-1);
	calc_matrix((void *)cylinder, CYLINDER);
	ft_lstadd(&(obj->cylinder), ft_lstnew(cylinder, sizeof(t_cylinder)));
	return (0);
}
