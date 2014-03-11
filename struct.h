/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 18:53:15 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/11 17:54:32 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <pthread.h>
# define X			(0)
# define Y			(1)
# define Z			(2)
# define SPHERE		(0)
# define PLANE		(1)
# define CYLINDER	(2)
# define CONE		(3)

typedef struct		s_coord
{
	float			x;
	float			y;
	float			z;
}					t_coord;

typedef t_point t_coord;

typedef struct		s_limit
{
	int				i;
	int				j;
}					t_limit;

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

typedef struct		s_sphere
{
	int				radius;
	t_coord			pos;
	int				color;
}					t_sphere;

typedef struct		s_plane
{
	t_coord			pos;
	t_coord			rot;
	int				color;
}					t_plane;

typedef struct		s_spot
{
	t_coord			coord;
	float			value;
	int				color;
}					t_spot;

typedef struct		s_info
{
	t_line			line;
	t_coord			pos;
	t_coord			vec_n;
	t_coord			vec_r;
	float			distance;
	float			light;
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
	t_cam			*cam;
}					t_obj;

typedef struct		s_thread
{
	pthread_t		th;
	int				id;
	int				start_i;
	int				start_j;
	int				end_i;
	int				end_j;
	t_param			*p;
}					t_thread;

typedef struct		s_equa
{
	float			a;
	float			b;
	float			c;
	float			delta;
}					t_equa;

#endif
