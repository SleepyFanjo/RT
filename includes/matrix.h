/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 15:20:04 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/26 10:24:12 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# define P_A	0
# define P_B	1
# define P_C	2
# define P_D	3
# define P_E	4
# define P_F	5
# define P_AD	6
# define P_BD	7
# define TI		0
# define TJ		1
# define ID		2
# define JD		3
# include "raytracer.h"

void	fill_matrix_rot(double *matrix, t_coord rot);
void	apply_matrix(double *matrix, t_coord *move);
void	invert_matrix(double *res, double *m);
void	transpose_matrix(double *res, double *m);
void	fill_matrix_trans(double *matrix, t_coord trans);
void	apply_transformation(double *m, t_coord *p);

#endif
