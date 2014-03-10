/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_get_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 15:47:13 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/03 18:47:39 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

int			get_sphere(t_obj *obj, char *line)
{
	char		**tab;
	int			i;
	t_sphere	*sphere;

	i = 0;
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		print_error("Allocation Fail");
	if (get_size_tab(tab) != 5)
		print_error("Line \"%s\" has no five param");
	if (!test_tab(tab, 4))
		print_error("Line \"%s\" is not ok");
	if ((sphere = (t_sphere *)malloc(sizeof(t_sphere))) == NULL)
		print_error("Allocation Fail");
	sphere->center.x = ft_atoi(tab[0]);
	sphere->center.y = ft_atoi(tab[1]);
	sphere->center.z = ft_atoi(tab[2]);
	sphere->radius = ft_atoi(tab[3]);
	if ((sphere->color = (int *)malloc(sizeof(int))) == NULL)
		print_error("Allocation Fail\n");
	*(sphere->color) = ft_atoi(tab[4]);
	ft_lstadd(&(obj->sphere), ft_lstnew(sphere, sizeof(t_sphere)));
	return (0);
}
