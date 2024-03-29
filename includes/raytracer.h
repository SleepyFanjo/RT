/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 13:13:36 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/27 16:14:38 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H
# define LOADING		(0)
# define F_PI			(3.1415926535)
# define WIDTH			(800)
# define HEIGHT			(600)
# define AMBL			0.0
# define RAD(deg)			(deg * F_PI / 180)
# include "multithread_struct.h"
# include <struct.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/list.h"
# define SQR(val)			(val * val)
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "define.h"
# define CD_NOT_CMD -1
# define CD_ERROR 0
# define CD_SPHERE 1
# define CD_PLAN 2
# define CD_SPOT 3
# define CD_CAM 4
# define CD_COM 5
# define CD_CYLINDER 6
# define CD_CONE 7

void	free_obj_lst(t_param *p);
void	init_param(t_param *param, char *dir);
int		test_tab(char **tab, int s_i);
int		get_type_obj(char *line);
t_obj	*get_obj(void);
int		get_size_tab(char **tab);
void	print_error(char *str1, char *str2);
void	add_in_list(t_list **list, t_list *elem);
int		get_cone(t_obj *obj, char *str);
int		get_cylinder(t_obj *obj, char *str);
int		get_spot(t_obj *obj, char *str);
int		get_plan(t_obj *obj, char *str);
int		get_sphere(t_obj *obj, char *str);
int		get_cam(t_obj *obj, char *line);
int		*get_color(char *color);
void	*free_spot(void *data);
int		ft_hex_atoi(char *str);
int		next_number(char *line, int *i);
int		first_number(char *line, int *i);
t_coord	init_cam(t_coord *rot, char *dir);
void	ft_error(char *s1, char *s2, int mode);
void	*j_malloc(size_t size);
int		put_pixel_to_img(t_param *param, int i, int j);
void	parser(char *filename, t_param *param);
t_info	*init_info(t_param *param, int i, int j);
void	write_on_img(t_param *param, int color, int i, int j);
int		raytracer(t_param *param, t_inf_exec *inf, int sockfd);
void	apply_trans(double *m, t_coord *move);
void	apply_rot(double *m, t_coord *move);
void	apply_rot_norm(double *m, t_coord *move);
void	calc_matrix(void *obj, int obj_type);
void	inter_sphere(t_info *info, t_list *sphere);
void	write_on_img(t_param *param, int color, int i, int j);
double	limited_sphere(t_sphere *obj, t_line line, double *dist);
double	limited_cylinder(t_cylinder *obj, t_line line, double *dist);
double	limited_cone(t_cone *obj, t_line line, double *dist);
void	inter_plane(t_info *info, t_list *plane);
void	inter_cylinder(t_info *info, t_list *cylinder);
void	inter_cone(t_info *info, t_list *cone);
void	calc_intersection(t_param *param, t_info *info);
void	calc_normal(t_info *info);
t_coord	sphere_vec_n(t_info *info, t_sphere *obj);
t_coord	plane_vec_n(t_info *info, t_plane *obj);
t_coord	cylinder_vec_n(t_info *info, t_cylinder *obj);
t_coord	cone_vec_n(t_info *info, t_cone *obj);
void	calc_light(t_param *param, t_info *info, t_list *spot);
void	calc_reflex(t_param *param, t_info *info);
int		calc_color_end(t_param *param, t_info *info);
void	swap_double(double *a, double *b);
void	init_ui(t_param *param);
int		final_color(int *color, double light);
int		ft_listen(int port);
void	get_env(int sockfd, t_inf_env *e);

#endif
