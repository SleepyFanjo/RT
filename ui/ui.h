/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 15:51:35 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/22 15:50:06 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

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

int		arrows(int keycode, t_param *param);
int		zoom(int keycode, t_param *param);
int		wasd(int keycode, t_param *param);
int		render(int keycode, t_param *param);

#endif
