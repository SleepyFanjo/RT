/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 15:51:35 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/23 15:22:13 by lredoban         ###   ########.fr       */
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

# define C_X param->cam.x
# define C_Y param->cam.y
# define C_Z param->cam.z
# define CR_X param->rot_cam.x
# define CR_Y param->rot_cam.y
# define CR_Z param->rot_cam.z
# define R param->ui->render
# define L param->ui->live

/*
**	key1.c
*/
int		arrows(int keycode, t_param *param);
int		zoom(int keycode, t_param *param);
int		wasd(int keycode, t_param *param);
int		render(int keycode, t_param *param);
int		save(int keycode, t_param *param);
int		live(int keycode, t_param *param);

/*
**	save.c
*/
void		put_sphere(t_param *param, int fd);
void		put_cam(t_param *param, int fd);
void		put_spot(t_param *param, int fd);
void		put_plane(t_param *param, int fd);
void		put_cone(t_param *param, int fd);
void		put_cylinder(t_param *param, int fd);
#endif
