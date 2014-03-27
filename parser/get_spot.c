/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 17:37:17 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 16:16:02 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int			fill_spot(t_spot *spot, char **tab)
{
	spot->coord.x = ft_atoi(tab[0]);
	spot->coord.y = ft_atoi(tab[1]);
	spot->coord.z = ft_atoi(tab[2]);
	spot->value = ft_atoi(tab[3]) / 100.0;
	if ((spot->color = get_color(tab[4])) == NULL)
		return (-1);
	return (0);
}

int			get_spot(t_obj *obj, char *line)
{
	char		**tab;
	t_spot		*spot;

	if ((tab = ft_strsplit(line, ' ')) == NULL)
	{
		ft_printf("%rAllocation Fail ");
		return (-1);
	}
	if (get_size_tab(tab) != 5)
	{
		ft_printf("%rThis line has no five param\n");
		return (-1);
	}
	if (!test_tab(tab, 4))
		return (-1);
	if ((spot = (t_spot *)malloc(sizeof(t_spot))) == NULL)
	{
		ft_printf("%rAllocation Fail ");
		return (-1);
	}
	if (fill_spot(spot, tab))
		return (-1);
	ft_lstadd(&(obj->spot), ft_lstnew(spot, sizeof(t_spot)));
	free(tab);
	return (0);
}
