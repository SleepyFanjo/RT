/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 12:51:11 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/22 17:00:10 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include "ui.h"

void		init_ui(t_param *param)
{
	if (!(param->ui = (t_ui *)malloc(sizeof(t_ui))))
		exit (0);
	param->ui->render = 1;
}
