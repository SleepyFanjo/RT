/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 15:58:58 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/27 15:21:19 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <fcntl.h>

static t_coord	get_rot(char *str, int i)
{
	t_coord		rot;

	rot.x = ft_atoi(str + next_number(str, &i));
	rot.y = ft_atoi(str + next_number(str, &i));
	rot.z = ft_atoi(str + next_number(str, &i));
	return (rot);
}
