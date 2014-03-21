/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 18:53:15 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/21 15:14:00 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define X			(0)
# define Y			(1)
# define Z			(2)
# include <list.h>
# include <pthread.h>
# define PIX		(img.pix)
# define BPP		(img.bpp)
# define LINE		(img.line)
# define ENDIAN		(img.endian)
# define SPHERE		(0)
# define PLANE		(1)
# define CYLINDER	(2)
# define CONE		(3)

typedef struct		s_coord
{
	double			x;
	double			y;
	double			z;
}					t_coord;

typedef struct		s_lim
{
	int				i;
	int				j;
}					t_lim;

typedef struct		s_line
{
	t_coord			pos;
	t_coord			vec;
}					t_line;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
}					t_env;

typedef struct		s_cam
{
	t_coord			point;
	int				rot[3];
}					t_cam;

typedef struct		s_img
{
	char			*pix;
	int				bpp;
	int				line;
	int				endian;
}					t_img;

typedef struct		s_material
{
	double			shine;
	double			reflex;
	double			med_in;
	double			refrax;
}					t_material;

typedef struct		s_sphere
{
	int				radius;
	double			lim_h_x;
	double			lim_b_x;
	double			lim_h_y;
	double			lim_b_y;
	double			lim_h_z;
	double			lim_b_z;
	t_coord			pos;
	int				*color;
}					t_sphere;

typedef struct		s_plane
{
	t_coord			vec;
	double			d;
	t_coord			pos;
	int				*color;
}					t_plane;

typedef struct		s_cylinder
{
	t_coord			pos;
	t_coord			rot;
	double			d;
	int				radius;
	int				*color;
}					t_cylinder;

typedef struct		s_cone
{
	t_coord			pos;
	t_coord			rot;
	int				alpha;
	int				*color;
}					t_cone;

typedef struct		s_equa
{
	double			a;
	double			b;
	double			c;
	double			delta;
}					t_equa;

typedef struct		s_spot
{
	t_coord			coord;
	double			value;
	int				*color;
}					t_spot;

typedef struct		s_info
{
	t_line			r_line;
	t_line			s_line;
	t_coord			r_pos;
	t_coord			s_pos;
	t_coord			vec_n;
	t_coord			vec_r;
	double			distance;
	double			light;
	int				*color;
	int				obj_type;
	void			*obj;
}					t_info;

typedef struct		s_param
{
	t_env			env;
	t_coord			cam;
	t_coord			rot_cam;
	t_list			*spot;
	t_list			*sphere;
	t_list			*plane;
	t_list			*cylinder;
	t_list			*cone;
}					t_param;

typedef struct		s_obj
{
	t_list			*plan;
	t_list			*cylinder;
	t_list			*spot;
	t_list			*sphere;
	t_list			*cone;
	t_cam			*cam;
}					t_obj;

typedef struct		s_var_parser
{
	int				num_line;
	int				cur_obj;
	t_obj			*obj;
	int				ret;
	char			*line;
}					t_var_parser;

# include "multithread_struct.h"

#endif
