/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 17:07:16 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/10 18:49:30 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void		inter_sphere(t_param *param, t_info *info, t_list *sphere)
{
	t_line		new;
	t_sphere	*obj;

	while (sphere && *sphere)
	{
		obj = (t_sphere *)sphere->content;
		new = get_new_equa(obj, info->line);
		dist = delta(new, obj);
		if (dist > 0 && (info->distance < 0 || dist < info->distance))
			update_info(info, dist, sphere->content);
		sphere = sphere->next;
	}
}
