/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 14:26:09 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/23 15:07:22 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "raytracer.h"

# define DAMIER		1
# define TEXT_1		2
# define TEXT_2		3

double		norme(t_coord vect);
t_coord		normalize(t_coord vec);
double		dot_product(t_coord p1, t_coord p2);
int 		*init_color(void);
int 		*retrieve_col(int *col, int *obj_col, double coef);
int			*damer(t_info *info, t_coord point);

double		get_shine(t_info *info);
double		get_med(t_info *info);
double		get_reflex(t_info *info);
int			get_texture(t_info *info);
#endif
