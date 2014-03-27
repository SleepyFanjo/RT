/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:24:27 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 15:24:31 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/network.h"

static void		v_exit(char *str, int cd)
{
	ft_printf(str);
	exit(cd);
}

static void		get_text_sequel(t_v_env *param, void *e)
{
	T5.file = "./textures/5.xpm";
	T5.img = mlx_xpm_file_to_image(e, T5.file, &T5.size_x, &T5.size_y);
	if (T5.img == NULL)
		v_exit("%r#20", 20);
	T5.data = mlx_get_data_addr(T5.img, &T5.bpp, &T5.sizeline, &T5.endian);
	T6.file = "./textures/6.xpm";
	T6.img = mlx_xpm_file_to_image(e, T6.file, &T6.size_x, &T6.size_y);
	if (T6.img == NULL)
		v_exit("%r#20", 20);
	T6.data = mlx_get_data_addr(T6.img, &T6.bpp, &T6.sizeline, &T6.endian);
	T7.file = "./textures/7.xpm";
	T7.img = mlx_xpm_file_to_image(e, T7.file, &T7.size_x, &T7.size_y);
	if (T7.img == NULL)
		v_exit("%r#20", 20);
	T7.data = mlx_get_data_addr(T7.img, &T7.bpp, &T7.sizeline, &T7.endian);
	T8.file = "./textures/8.xpm";
	T8.img = mlx_xpm_file_to_image(e, T8.file, &T8.size_x, &T8.size_y);
	if (T8.img == NULL)
		v_exit("%r#20", 20);
	T8.data = mlx_get_data_addr(T8.img, &T8.bpp, &T8.sizeline, &T8.endian);
}

void			get_textures(t_v_env *param, void *e)
{
	T0.file = "./textures/0.xpm";
	T0.img = mlx_xpm_file_to_image(e, T0.file, &T0.size_x, &T0.size_y);
	if (T0.img == NULL)
		v_exit("%r#20", 20);
	T0.data = mlx_get_data_addr(T0.img, &T0.bpp, &T0.sizeline, &T0.endian);
	T1.file = "./textures/1.xpm";
	T1.img = mlx_xpm_file_to_image(e, T1.file, &T1.size_x, &T1.size_y);
	if (T1.img == NULL)
		v_exit("%r#20", 20);
	T1.data = mlx_get_data_addr(T1.img, &T1.bpp, &T1.sizeline, &T1.endian);
	T2.file = "./textures/2.xpm";
	T2.img = mlx_xpm_file_to_image(e, T2.file, &T2.size_x, &T2.size_y);
	if (T2.img == NULL)
		v_exit("%r#20", 20);
	T2.data = mlx_get_data_addr(T2.img, &T2.bpp, &T2.sizeline, &T2.endian);
	T3.file = "./textures/3.xpm";
	T3.img = mlx_xpm_file_to_image(e, T3.file, &T3.size_x, &T3.size_y);
	if (T3.img == NULL)
		v_exit("%r#20", 20);
	T3.data = mlx_get_data_addr(T3.img, &T3.bpp, &T3.sizeline, &T3.endian);
	T4.file = "./textures/4.xpm";
	T4.img = mlx_xpm_file_to_image(e, T4.file, &T4.size_x, &T4.size_y);
	if (T4.img == NULL)
		v_exit("%r#20", 20);
	T4.data = mlx_get_data_addr(T4.img, &T4.bpp, &T4.sizeline, &T4.endian);
	get_text_sequel(param, e);
}
