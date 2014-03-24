#include "../includes/network.h"

t_v_env		*send_env(t_list *lst)
{
	t_client	*cl;
	t_img		*img;
	t_v_env		*env;
	int			test;
	t_my_mlx	*mlx;

	env = malloc(sizeof(t_v_env));
	init_env(env);
	mlx = (t_my_mlx *)env->mlx;
	img = malloc(sizeof(t_img));
	img->bpp = env->bpp;
	img->line = env->line;
	img->endian = env->endian;
	img->decrgb = mlx->decrgb;
	img->depth = mlx->depth;
	while (lst != NULL)
	{
		cl = (t_client *)lst->content;
		if (send_message(cl->sockfd, sizeof(t_img), img) < 0)
		{
			ft_printf("%rError #17 cl:%s\n", cl->name_host_cl);
			lst = lst->next;
			continue ;
		}
		if (send_message(cl->sockfd, sizeof(int) * 6, img->decrgb) < 0)
		{
			ft_printf("%rError #16, cl: %s\n", cl->name_host_cl);
			lst = lst->next;
			continue ;
		}
		if (get_value(cl->sockfd, &test, sizeof(int)) < 0 || test != SIZE_SUCCES)
		{
			ft_printf("%rError #15\n");
			lst = lst->next;
			continue ;
		}
		lst = lst->next;
	}
	free(img);
	return (env);
}
