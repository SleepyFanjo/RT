/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_get_plan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 17:19:28 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/03 18:55:55 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt.h"

int			get_plan(t_obj *obj, char *line)
{
	char		**tab;
	int			i;
	t_plan		*plan;

	i = 0;
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		print_error("Allocation Fail");
	if (get_size_tab(tab) != 7)
		print_error("Line \"%s\" has no five param");
	if (!test_tab(tab, 6))
		print_error("Line \"%s\" is not ok");
	if ((plan = (t_plan *)malloc(sizeof(t_plan))) == NULL)
		print_error("Allocation Fail");
	plan->point.x = ft_atoi(tab[0]);
	plan->point.y = ft_atoi(tab[1]);
	plan->point.z = ft_atoi(tab[2]);
	plan->vector.x = ft_atoi(tab[3]);
	plan->vector.y = ft_atoi(tab[4]);
	plan->vector.z = ft_atoi(tab[5]);
	if ((plan->color = (int *)malloc(sizeof(int))) == NULL)
		print_error("Allocation Fail\n");
	*(plan->color) = ft_atoi(tab[6]);
	ft_lstadd(&(obj->plan), ft_lstnew(plan, sizeof(t_plan)));
	return (0);
}
