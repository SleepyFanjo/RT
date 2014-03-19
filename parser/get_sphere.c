/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_get_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 15:47:13 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/19 14:33:53 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracer.h"

static void	set_sphere(t_sphere *obj, char **tab)
{
	obj->lim_h_x = ft_atoi(tab[4]);
	obj->lim_b_x = ft_atoi(tab[5]);
	obj->lim_h_y = ft_atoi(tab[6]);
	obj->lim_b_y = ft_atoi(tab[7]);
	obj->lim_h_z = ft_atoi(tab[8]);
	obj->lim_b_z = ft_atoi(tab[9]);
}

int			get_sphere(t_obj *obj, char *line)
{
	char		**tab;
	int			i;
	t_sphere	*sphere;

	i = 0;
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		print_error(line, "Allocation Fail");
	if (get_size_tab(tab) != 11)
		print_error(line, "has no five param");
	if (!test_tab(tab, 10))
		print_error(line, "is not ok");
	if ((sphere = (t_sphere *)malloc(sizeof(t_sphere))) == NULL)
		print_error(line, "Allocation Fail");
	sphere->pos.x = ft_atoi(tab[0]);
	sphere->pos.y = ft_atoi(tab[1]);
	sphere->pos.z = ft_atoi(tab[2]);
	sphere->radius = ft_atoi(tab[3]);
	sphere->color = get_color(tab[10]);
	set_sphere(sphere, tab);
	ft_lstadd(&(obj->sphere), ft_lstnew(sphere, sizeof(t_sphere)));
	return (0);
}
