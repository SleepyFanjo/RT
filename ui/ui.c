/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 12:51:11 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 01:07:26 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include "ui.h"

void		init_ui(t_param *param)
{
	if (!(param->ui = (t_ui *)malloc(sizeof(t_ui))))
		exit (0);
	R = START_MODE;
	L = 0;
	POS = &(param->cam);
	ROT = &(param->rot_cam);
	RADIUS = NULL;
	FOCUS = -1;
}

void		reinit_ui(t_param *param)
{
	(void)param;
}
