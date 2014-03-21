/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_get_plan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 17:19:28 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/21 16:15:35 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracer.h"

static void	set_plan(t_plane *plan, char **tab)
{
	plan->pos.x = ft_atoi(tab[0]);
	plan->pos.y = ft_atoi(tab[1]);
	plan->pos.z = ft_atoi(tab[2]);
	plan->vec.x = ft_atoi(tab[3]);
	plan->vec.y = ft_atoi(tab[4]);
	plan->vec.z = ft_atoi(tab[5]);
	plan->mat.shine = ft_atoi(tab[6]) / 100.0;
	plan->mat.reflex = ft_atoi(tab[7]) / 100.0;
	plan->mat.med_in = ft_atoi(tab[8]) / 100.0;
	plan->mat.refrax = ft_atoi(tab[9]) / 100.0;
	plan->color = get_color(tab[10]);
}

int			get_plan(t_obj *obj, char *line)
{
	char		**tab;
	int			i;
	t_plane		*plan;

	i = 0;
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		print_error(line, "Allocation Fail");
	if (get_size_tab(tab) != 11)
		print_error(line, "has no 11 param");
	if (!test_tab(tab, 10))
		print_error(line, "Plane is not ok");
	if ((plan = (t_plane *)malloc(sizeof(t_plane))) == NULL)
		print_error(line, "Allocation Fail");
	set_plan(plan, tab);
	plan->d = -(plan->pos.x * plan->vec.x) - (plan->pos.y * plan->vec.y)
				- (plan->pos.z * plan->vec.z);
	ft_lstadd(&(obj->plan), ft_lstnew(plan, sizeof(t_plane)));
	return (0);
}
