#include "../includes/network.h"

static t_img	*v_init_img(t_v_env *env)
{
	t_my_mlx	*mlx;
	t_img		*img;

	mlx = (t_my_mlx *)env->mlx;
	img = malloc(sizeof(t_img));
	img->bpp = env->bpp;
	img->line = env->line;
	img->endian = env->endian;
	img->decrgb = mlx->decrgb;
	img->depth = mlx->depth;
	return (img);
}

static void		loop_send_env(t_client *cl, t_img *img)
{
	int			test;

	if (send_message(cl->sockfd, sizeof(t_img), img) < 0)
	{
		ft_printf("%rError #17 cl:%s\n", cl->name_host_cl);
		return ;
	}
	if (send_message(cl->sockfd, sizeof(int) * 6, img->decrgb) < 0)
	{
		ft_printf("%rError #16, cl: %s\n", cl->name_host_cl);
		return ;
	}
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

	env = malloc(sizeof(t_v_env));
	init_env(env);
	img = v_init_img(env);
	while (lst != NULL)
	{
		cl = (t_client *)lst->content;
		loop_send_env(cl, img);
		lst = lst->next;
	}
	free(img);
	return (env);
}
