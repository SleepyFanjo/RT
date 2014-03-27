/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_get_plan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 17:19:28 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 16:08:06 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

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
	plan->mat.trans = ft_atoi(tab[10]) / 100.0;
	plan->mat.texture = ft_atoi(tab[11]);
	calc_matrix((void *)plan, PLANE);
}

int			get_plan(t_obj *obj, char *line)
{
	char		**tab;
	t_plane		*plan;

	if ((tab = ft_strsplit(line, ' ')) == NULL)
		return (-1);
	if (get_size_tab(tab) != 13)
	{
		ft_printf("%rThis line has no 13 param: ");
		return (-1);
	}
	if (!test_tab(tab, 12))
		return (-1);
	if ((plan = (t_plane *)malloc(sizeof(t_plane))) == NULL)
	{
		ft_printf("%rAllocation Fail");
		return (-1);
	}
	set_plan(plan, tab);
	plan->color = get_color(tab[12]);
	if (plan->color == NULL)
		return (-1);
	ft_lstadd(&(obj->plan), ft_lstnew(plan, sizeof(t_plane)));
	return (0);
}
