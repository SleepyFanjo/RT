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
	if (get_value(cl->sockfd, &test, sizeof(int)) < 0 ||
			test != SIZE_SUCCES)
	{
		ft_printf("%rError #15, cl: %s\n", cl->name_host_cl);
		return ;
	}
}

t_v_env			*send_env(t_list *lst)
{
	t_client	*cl;
	t_img		*img;
	t_v_env		*env;

	env = j_malloc(sizeof(t_v_env));
	init_env(env);
	img = v_init_img(env);
	while (lst != NULL)
	{
		cl = (t_client *)lst->content;
		loop_send_env(cl, img, env);
		lst = lst->next;
	}
	free(img);
	return (env);
}
