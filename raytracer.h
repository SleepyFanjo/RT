/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 13:13:36 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/15 19:09:04 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H
# define F_PI			(3.1415926535)
# define RAD(deg)			(deg * F_PI / 180)
# include <libft.h>
# include "struct.h"

int		expose_hook(t_param *param);
int		key_hook(t_param *param);
void	ft_error(char *s1, char *s2, int mode);
void	*j_malloc(size_t size);
void	raytracer(t_param *param, int nbr_process);
int		raythrow(t_thread *thread);
int		put_pixel_to_img(t_param *param, int i, int j);
void	fill_param(t_param *param, char *str);
t_info	*init_info(t_param *param, int i, int j);
void	apply_trans(t_coord translation, t_coord *to_move, int mult);
void	apply_rot(t_coord rotation, t_coord *to_turn, int mult);
void	apply_rot_x(t_coord *vec, float rot_x);
void	apply_rot_y(t_coord *vec, float rot_y);
void	apply_rot_z(t_coord *vec, float rot_z);
void	inter_sphere(t_param *param, t_info *info, t_list *sphere);
void	inter_plane(t_param *param, t_info *info, t_list *plane);
float	sqr(float nbr);

#endif
