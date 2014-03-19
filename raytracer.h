/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 13:13:36 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/19 18:30:42 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H
# define LOADING		(0)
# define F_PI			(3.1415926535)
# define WIDTH			(800)
# define HEIGHT			(600)
# define AMBL			0.2
# define RAD(deg)			(deg * F_PI / 180)
# define SQR(val)			(val * val)
# include <mlx.h>
# include <math.h>
# include <libft.h>
# include "struct.h"

void	init_param(t_param *param, char *dir);
void	add_in_list(t_list **list, t_list *elem);
t_list	*fill_spot_list(char *dir);
t_list	*fill_plane_list(char *dir);
t_list	*fill_cylinder_list(char *dir);
t_list	*fill_cone_list(char *dir);
int		*get_color(int color);
int		next_number(char *line, int *i);
int		first_number(char *line, int *i);
t_list	*get_sphere(char *str);
t_coord	init_cam(t_coord *rot, char *dir);
int		expose_hook(t_param *param);
int		key_hook(int keycode, t_param *param);
void	ft_error(char *s1, char *s2, int mode);
void	*j_malloc(size_t size);
void	raytracer(t_param *param, int nbr_process);
int		raythrow(t_thread *thread);
int		put_pixel_to_img(t_param *param, int i, int j);
void	parser(char *filename, t_param *param);
t_info	init_info(t_param *param, int i, int j);
void	write_on_img(t_param *param, int color, int i, int j);
void	apply_trans(t_coord translation, t_coord *to_move, int mult);
void	apply_rot(t_coord rotation, t_coord *to_turn, int mult);
void	apply_rotrans(t_coord rot, t_coord trans, t_coord *move, int mult);
void	inter_sphere(t_param *param, t_info *info, t_list *sphere);
double	limited_sphere(t_sphere *obj, t_line line, double dist);
void	inter_plane(t_param *param, t_info *info, t_list *plane);
void	inter_cylinder(t_param *param, t_info *info, t_list *cylinder);
void	inter_cone(t_param *param, t_info *info, t_list *cone);
void	calc_intersection(t_param *param, t_info *info);
void	calc_normal(t_info *info);
t_coord	sphere_vec_n(t_info *info, t_sphere *obj);
t_coord	plane_vec_n(t_plane *obj);
t_coord	cylinder_vec_n(t_info *info, t_cylinder *obj);
t_coord	cone_vec_n(t_info *info, t_cone *obj);
void	calc_light(t_param *param, t_info *info, t_list *spot);

#endif
