/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 15:51:35 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 09:43:32 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

# include "libftprintf.h"

# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
# define PLUS 65451
# define MINUS 65453
# define W 119
# define A 97
# define S 115
# define D 100
# define C 99
# define NINE 65465
# define SIX 65462
# define DEL 65288

# define C_X param->cam.x
# define C_Y param->cam.y
# define C_Z param->cam.z
# define CR_X param->rot_cam.x
# define CR_Y param->rot_cam.y
# define CR_Z param->rot_cam.z
# define R param->t->render
# define L param->t->live
# define OBJ param->ui->obj
# define POS param->ui->pos
# define ROT param->ui->rot
# define RADIUS param->ui->rad
# define FOCUS param->ui->focus

/*
**	key1.c
*/
int		render(int keycode, t_param *param);
int		save(t_param *param);
int		live(int keycode, t_param *param);
int		how_high(int keycode, t_param *param);
int		back_to_cam(int keycode, t_param *param);

/*
**	key2.c
*/
int		wasd(int keycode, t_param *param);
int		arrows(int keycode, t_param *param);
int		roll(int keycode, t_param *param);

/*
**	key3.c
*/
int		rad(int keycode, t_param *param);
int		del(int keycode, t_param *param);

/*
**	find_obj.c
*/
t_list		*find_cone(t_param *param, t_list *l);
t_list		*find_cylinder(t_param *param, t_list *l);
t_list		*find_plane(t_param *param, t_list *l);
t_list		*find_sphere(t_param *param, t_list *l);

/*
**	copy.c
*/
int		copy(int keycode, t_param *param);

/*
**	save.c
*/
void		put_cam(t_param *param, int fd);
void		put_spot(t_param *param, int fd);

/*
**  clic.c
*/
void		clic_sphere(t_param *param, t_info *info);
void		clic_plane(t_param *param, t_info *info);
void		clic_cylinder(t_param *param, t_info *info);
void		clic_cone(t_param *param, t_info *info);

/*
**  save_cc.c
*/
void		put_cylinder(t_param *param, int fd);
void		put_cone(t_param *param, int fd);

/*
**  save_sp.c
*/
void		put_sphere(t_param *param, int fd);
void		put_plane(t_param *param, int fd);
#endif
