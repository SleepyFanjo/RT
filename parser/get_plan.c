/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_get_plan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 17:19:28 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/25 16:00:40 by qchevrin         ###   ########.fr       */
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
}

int			get_plan(t_obj *obj, char *line)
{
	char		**tab;
	int			i;
	t_plane		*plan;

	i = 0;
	if ((tab = ft_strsplit(line, ' ')) == NULL)
	{
		ft_printf("%rAllocation Fail: ");
		return (-1);
	}
	if (get_size_tab(tab) != 11)
	{
		ft_printf("%rThis line has no 11 param: ");
		return (-1);
	}
	if (!test_tab(tab, 10))
		return (-1);
	if ((plan = (t_plane *)malloc(sizeof(t_plane))) == NULL)
	{
		ft_printf("%rAllocation Fail");
		return (-1);
	}
	set_plan(plan, tab);
	plan->color = get_color(tab[10]);
	if (plan->color == NULL)
		return (-1);
	plan->d = -(plan->pos.y);
	ft_lstadd(&(obj->plan), ft_lstnew(plan, sizeof(t_plane)));
	return (0);
}
