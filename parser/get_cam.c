/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 17:40:51 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 10:51:11 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static int		cam_test_tab(char **tab, int s_i)
{
	int		i;
	int		j;

	i = 0;
	while (i < s_i)
	{
		j = ft_strlen(tab[i]) - 1;
		while (j >= 0 && ft_isdigit(tab[i][j]))
			j--;
		while (j >= 0 && tab[i][j] == '-')
			j--;
		if (j >= 0)
			return (0);
		i++;
	}
	return (1);
}

int				get_cam(t_obj *obj, char *line)
{
	char		**tab;
	t_cam		*plan;

	if (obj->cam != NULL)
		print_error(line, "Cam was already defined\n");
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		print_error(line, "Allocation Fail");
	if (get_size_tab(tab) != 6)
		print_error(line, "has no six param");
	if (!cam_test_tab(tab, 6))
		print_error(line, "is not ok");
	if ((plan = (t_cam *)malloc(sizeof(t_cam))) == NULL)
		print_error(line, "Allocation Fail");
	plan->point.x = ft_atoi(tab[0]);
	plan->point.y = ft_atoi(tab[1]);
	plan->point.z = ft_atoi(tab[2]);
	plan->rot.x = ft_atoi(tab[3]);
	plan->rot.y = ft_atoi(tab[4]);
	plan->rot.z = ft_atoi(tab[5]);
	obj->cam = plan;
	return (0);
}
