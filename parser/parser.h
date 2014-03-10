/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 13:57:53 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/10 18:36:04 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <stdio.h>


# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include "libft/includes/list.h"

# define W				800
# define H				600
# define AMBL			0
# define PI				3.1415926

# define CD_NOT_CMD -1
# define CD_ERROR 0
# define CD_SPHERE 1
# define CD_PLAN 2
# define CD_SPOT 3
# define CD_CAM 4
# define CD_COM 5
# define CD_CYLINDER 6

# include "struct.h"

int						get_sphere(t_obj *obj, char *line);
void					print_error(char *str);
int						get_size_tab(char **tab);
int						test_tab(char **tab, int s_i);
int						v_get_cam(t_obj *obj, char *line);
int						get_plan(t_obj *obj, char *line);
int						get_cylinder(t_obj *obj, char *line);
int						get_spot(t_obj *obj, char *line);
t_obj					*parser(char *filename);
t_obj					*get_obj(void);
int						get_type_obj(char *line);

#endif
