/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:18:18 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 16:06:55 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static void	set_cone(t_cone *cone, char **tab)
{
	cone->pos.x = ft_atoi(tab[0]);
	cone->pos.y = ft_atoi(tab[1]);
	cone->pos.z = ft_atoi(tab[2]);
	cone->rot.x = ft_atoi(tab[3]);
	cone->rot.y = ft_atoi(tab[4]);
	cone->rot.z = ft_atoi(tab[5]);
	cone->alpha = ft_atoi(tab[6]);
	cone->is_limited = ft_atoi(tab[7]);
	cone->lim_h = ft_atoi(tab[8]);
	cone->lim_b = ft_atoi(tab[9]);
	cone->mat.shine = ft_atoi(tab[10]) / 100.0;
	cone->mat.reflex = ft_atoi(tab[11]) / 100.0;
	cone->mat.med_in = ft_atoi(tab[12]) / 100.0;
	cone->mat.refrax = ft_atoi(tab[13]) / 100.0;
	cone->mat.trans = ft_atoi(tab[14]) / 100.0;
	cone->mat.texture = ft_atoi(tab[15]);
	calc_matrix((void *)cone, CONE);
}

int			get_cone(t_obj *obj, char *line)
{
	char		**tab;
	t_cone		*cone;

	if ((tab = ft_strsplit(line, ' ')) == NULL)
	{
		ft_printf("%rAllocation Fail: ");
		return (-1);
	}
	if (get_size_tab(tab) != 17)
	{
		ft_printf("%rCone has no 17 param(%d): ", get_size_tab(tab));
		return (-1);
	}
	if (!test_tab(tab, 16))
		return (-1);
	if ((cone = (t_cone *)malloc(sizeof(t_cone))) == NULL)
		ft_printf("%rAllocation Fail: ");
	if ((cone->color = get_color(tab[16])) == NULL)
	{
		ft_printf("%rAllocation Fail: ");
		return (-1);
	}
	set_cone(cone, tab);
	ft_lstadd(&(obj->cone), ft_lstnew(cone, sizeof(t_cone)));
	return (0);
}
