/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 14:26:09 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/25 12:23:32 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "raytracer.h"

# define DAMIER		1
# define TEXT_0		2
# define TEXT_1		3
# define TEXT_2		4
# define TEXT_3		5
# define TEXT_4		6
# define TEXT_5		7
# define TEXT_6		8
# define TEXT_7		9
# define TEXT_8		10

double		norme(t_coord vect);
t_coord		normalize(t_coord vec);
double		dot_product(t_coord p1, t_coord p2);
int 		*init_color(void);
int 		*retrieve_col(int *col, int *obj_col, double coef);
int			*damer(t_param *param, t_info *info, t_coord point);
t_coord		calc_v_reflex(t_coord ov_dir, t_coord ov_nor);

double		get_shine(t_info *info);
double		get_med(t_info *info);
double		get_reflex(t_info *info);
int			get_texture(t_info *info);
#endif
