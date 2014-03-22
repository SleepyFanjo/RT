/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 16:03:33 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/21 16:12:41 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void		swap_double(double *a, double *b)
{
	double		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}