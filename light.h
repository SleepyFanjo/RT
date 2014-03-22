/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 14:26:09 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/22 14:37:15 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "raytracer.h"

double	norme(t_coord vect);
t_coord	normalize(t_coord vec);
double	dot_product(t_coord p1, t_coord p2);
int 	*init_color(void);

#endif
