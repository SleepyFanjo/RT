/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 12:51:11 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/26 14:12:25 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include "ui.h"

void		init_ui(t_param *param)
{
	if (!(param->ui = (t_ui *)malloc(sizeof(t_ui))))
		exit (0);
	R = 1;
	L = 0;
	POS = &(param->cam);
	ROT = &(param->rot_cam);
	B_ROT = 1;
	param->t->render = START_MODE;
}

void		reinit_ui(t_param *param)
{
	param->t->render = START_MODE;
}
