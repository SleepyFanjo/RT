/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 17:37:17 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/03 18:58:42 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			get_spot(t_obj *obj, char *line)
{
	char		**tab;
	int			i;
	t_spot		*spot;

	i = 0;
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		print_error("Allocation Fail");
	if (get_size_tab(tab) != 5)
		print_error("Line \"%s\" has no five param");
	if (!test_tab(tab, 4))
		print_error("Line \"%s\" is not ok");
	if ((spot = (t_spot *)malloc(sizeof(t_spot))) == NULL)
		print_error("Allocation Fail");
	spot->point.x = ft_atoi(tab[0]);
	spot->point.y = ft_atoi(tab[1]);
	spot->point.z = ft_atoi(tab[2]);
	spot->light = ft_atoi(tab[3]);
	spot->color = ft_atoi(tab[4]);
	ft_lstadd(&(obj->spot), ft_lstnew(spot, sizeof(t_spot)));
	return (0);
}
