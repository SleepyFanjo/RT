/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 09:56:12 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 10:19:28 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "ui.h"

void		put_cam(t_param *param, int fd)
{
	ft_putendl_fd("//cam\n#cam pos_x pos_y pos_z rot_x rot_y rot_z", fd);
	l_printf("%q%d %d %d %d %d %d\n", fd, (int)C_X, (int)C_Y, (int)C_Z
		, (int)CR_X, (int)CR_Y, (int)CR_Z);
}

static void lil_put_spot(t_spot *s, int fd)
{
	int		value;

	value = (int)(s->value * 100);
	l_printf("%q%d %d %d %d ", fd, (int)s->coord.x, (int)s->coord.y
		, (int)s->coord.z, value);
	l_printf("%q%X%X%X\n", fd, s->color[2], s->color[1], s->color[0]);
}

void		put_spot(t_param *param, int fd)
{
	t_spot		*s;
	t_list		*list;

	list = param->spot;
	ft_putendl_fd("//spot", fd);
	while (list != NULL)
	{
		s = list->content;
		lil_put_spot(s, fd);
		list = list->next;
	}
}
