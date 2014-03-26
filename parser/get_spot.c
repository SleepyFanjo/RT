/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 17:37:17 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/26 15:08:51 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

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
		ft_printf("%rThis line has no five param\n");
	if (!test_tab(tab, 4))
		return (-1);
	if ((spot = (t_spot *)malloc(sizeof(t_spot))) == NULL)
	{
		ft_printf("%rAllocation Fail ");
		return (-1);
	}
	spot->coord.x = ft_atoi(tab[0]);
	spot->coord.y = ft_atoi(tab[1]);
	spot->coord.z = ft_atoi(tab[2]);
	spot->value = ft_atoi(tab[3]) / 1000.0;
	if ((spot->color = get_color(tab[4])) == NULL)
		return (-1);
	ft_lstadd(&(obj->spot), ft_lstnew(spot, sizeof(t_spot)));
	free(tab);
	return (0);
}
