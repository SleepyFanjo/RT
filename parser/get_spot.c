/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 17:37:17 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/19 15:49:05 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracer.h"

int			get_spot(t_obj *obj, char *line)
{
	char		**tab;
	int			i;
	t_spot		*spot;

	i = 0;
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		print_error(line, "Allocation Fail");
	if (get_size_tab(tab) != 5)
		print_error(line, "has no five param");
	if (!test_tab(tab, 4))
		print_error(line, "is not ok");
	if ((spot = (t_spot *)malloc(sizeof(t_spot))) == NULL)
		print_error(line, "Allocation Fail");
	spot->coord.x = ft_atoi(tab[0]);
	spot->coord.y = ft_atoi(tab[1]);
	spot->coord.z = ft_atoi(tab[2]);
	spot->value = ft_atoi(tab[3]) / 1000.0;
	spot->color = get_color(tab[4]);
	ft_lstadd(&(obj->spot), ft_lstnew(spot, sizeof(t_spot)));
	return (0);
}
