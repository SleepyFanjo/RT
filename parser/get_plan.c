/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_get_plan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 17:19:28 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/19 15:26:04 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracer.h"

int			get_plan(t_obj *obj, char *line)
{
	char		**tab;
	int			i;
	t_plane		*plan;

	i = 0;
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		print_error(line, "Allocation Fail");
	if (get_size_tab(tab) != 7)
		print_error(line, "has no five param");
	if (!test_tab(tab, 6))
		print_error(line, "Plane is not ok");
	if ((plan = (t_plane *)malloc(sizeof(t_plane))) == NULL)
		print_error(line, "Allocation Fail");
	plan->pos.x = ft_atoi(tab[0]);
	plan->pos.y = ft_atoi(tab[1]);
	plan->pos.z = ft_atoi(tab[2]);
	plan->vec.x = ft_atoi(tab[3]);
	plan->vec.y = ft_atoi(tab[4]);
	plan->vec.z = ft_atoi(tab[5]);
	plan->d = -1 * (plan->pos.x * plan->vec.x) - (plan->pos.y * plan->vec.y);
	if ((plan->color = (int *)malloc(sizeof(int))) == NULL)
		print_error(line, "Allocation Fail\n");
	plan->color = get_color(tab[6]);
	ft_lstadd(&(obj->plan), ft_lstnew(plan, sizeof(t_plane)));
	return (0);
}
