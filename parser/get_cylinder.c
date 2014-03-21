/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 17:29:34 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/21 16:16:09 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracer.h"

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
	cylinder->color = get_color(tab[11]);
}

int			get_cylinder(t_obj *obj, char *line)
{
	char		**tab;
	int			i;
	t_cylinder	*cylinder;

	i = 0;
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		print_error(line, "Allocation Fail");
	if (get_size_tab(tab) != 8)
		print_error(line, "Cylinder has no 12 param");
	if (!test_tab(tab, 7))
		print_error(line, "Cylinder is not ok");
	if ((cylinder = (t_cylinder *)malloc(sizeof(t_cylinder))) == NULL)
		print_error(line, "Allocation Fail");
	if ((cylinder->color = (int *)malloc(sizeof(int))) == NULL)
		print_error(line, "Allocation Fail\n");
	set_cylinder(cylinder, tab);
	ft_lstadd(&(obj->cylinder), ft_lstnew(cylinder, sizeof(t_cylinder)));
	return (0);
}
