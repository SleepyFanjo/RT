/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 12:06:37 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 12:06:38 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/network.h"

static t_img	*v_init_img(t_v_env *env)
{
	t_my_mlx	*mlx;
	t_img		*img;

	mlx = (t_my_mlx *)env->mlx;
	img = j_malloc(sizeof(t_img));
	bzero(img, sizeof(t_img));
	img->bpp = env->bpp;
	img->line = env->line;
	img->endian = env->endian;
	img->decrgb = mlx->decrgb;
	img->depth = mlx->depth;
	img->addr = NULL;
	return (img);
}

static int		send_textures(int sockfd, t_v_env *env)
{
	int			i;
	t_textures	*tex;
	int			size;

	i = 0;
	while (i < NB_T)
	{
		tex = ((t_textures *)(env->text)) + i;
		if (send_long_message(sockfd, tex, sizeof(t_textures)) < 0)
			return (-1);
		size = tex->size_y * tex->sizeline;
		if (send_long_message(sockfd, tex->data, size) < 0)
			return (-1);
		i++;
	}
	return (0);
}

static void	v_exit(char *msg, int cd)
{
	ft_printf(msg);
	exit(cd);
}

static void		loop_send_env(t_client *cl, t_img *img, t_v_env *env)
{
	int			test;

	if (send_message(cl->sockfd, sizeof(t_img), (void *)img) < 0)
	{
		ft_printf("%rError #17 cl:%s\n", cl->name_host_cl);
		return ;
	}
	if (send_message(cl->sockfd, sizeof(int) * 6, img->decrgb) < 0)
	{
		ft_printf("%rError #16, cl: %s\n", cl->name_host_cl);
		return ;
	}
	if (send_textures(cl->sockfd, env) < 0)
		v_exit("%rError #23\n", 23);
	if (send_long_message(cl->sockfd, env->p->t, sizeof(t_event)) < 0)
		v_exit("%rError #26\n", 26);
	if (get_value(cl->sockfd, &test, sizeof(int)) < 0 ||
			test != SIZE_SUCCES)
	{
		ft_printf("%rError #15, cl: %s\n", cl->name_host_cl);
		return ;
	}
}

void		send_env(t_list *lst, t_v_env *e)
{
	t_client	*cl;
	t_img		*img;

	img = v_init_img(e);
	while (lst != NULL)
	{
		cl = (t_client *)lst->content;
		loop_send_env(cl, img, e);
		lst = lst->next;
	}
	free(img);
}
