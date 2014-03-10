/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 10:34:55 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/10 11:00:49 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# define X			(0)
# define Y			(1)
# define Z			(2)

typedef struct		s_coord
{
	float			coord[3];
}					t_coord;

typedef struct		s_limit
{
	int				i;
	int				j;
}					t_limit;

typedef struct		s_line
{
	t_coord			*pos;
	t_coord			*vec;
}					t_line;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
}					t_env;

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
	t_coord			*pos;
	int				*color;
}					t_sphere;

typedef struct		s_plane
{
	float			a;
	float			b;
	float			c;
	float			d;
	int				*color;
}					t_plane;

typedef struct		s_spot
{
	t_coord			*coord;
	float			value;
	int				*color;
}					t_spot;

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

typedef struct		s_info
{
	t_coord			*pos;
	t_coord			*vec_n;
	t_coord			*vec_r;
	float			distance;
	float			light;
	int				obj_type;
	void			*obj;
}					t_info;

typedef struct		s_param
{
	t_env			*env;
	t_cam			*cam;
	t_list			*spot;
	t_list			*sphere;
	t_list			*plane;
	t_list			*cylindre;
	t_list			*cone;
}					t_param;
