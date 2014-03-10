/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 17:29:34 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/04 13:52:00 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	set_cylinder(t_cylinder *cylinder, char **tab)
{
	cylinder->vect.x = ft_atoi(tab[0]);
	cylinder->vect.y = ft_atoi(tab[1]);
	cylinder->vect.z = ft_atoi(tab[2]);
	cylinder->rot[0] = ft_atoi(tab[3]);
	cylinder->rot[1] = ft_atoi(tab[4]);
	cylinder->rot[2] = ft_atoi(tab[5]);
	cylinder->radius = ft_atoi(tab[6]);
	cylinder->height = ft_atoi(tab[7]);
	*(cylinder->color) = ft_atoi(tab[8]);
}

int			get_cylinder(t_obj *obj, char *line)
{
	char		**tab;
	int			i;
	t_cylinder	*cylinder;

	i = 0;
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		print_error("Allocation Fail");
	if (get_size_tab(tab) != 9)
		print_error("Cylinder has no five param");
	if (!test_tab(tab, 8))
		print_error("Cylinder is not ok");
	if ((cylinder = (t_cylinder *)malloc(sizeof(t_cylinder))) == NULL)
		print_error("Allocation Fail");
	if ((cylinder->color = (int *)malloc(sizeof(int))) == NULL)
		print_error("Allocation Fail\n");
	set_cylinder(cylinder, tab);
	ft_lstadd(&(obj->cylinder), ft_lstnew(cylinder, sizeof(t_cylinder)));
	return (0);
}
