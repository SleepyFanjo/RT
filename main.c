/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 11:17:34 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/21 18:10:34 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void		ft_error(char *s1, char *s2, int mode)
{
	ft_putstr_fd(s1, 2);
	if (s2 != NULL)
		ft_putstr_fd(s2, 2);
	ft_putstr_fd("\n", 2);
	if (mode)
		exit(mode);
}

void		*j_malloc(size_t size)
{
	void	*ret;

	if ((ret = malloc(size)) == NULL)
	{
		if ((ret = malloc(size)) == NULL)
			ft_error("Error : can't malloc", NULL, 1);
	}
	return (ret);
}

int			main(int argc, char **argv)
{
	t_param		param;

	if (argc != 3)
	{
		ft_putendl("Error : incorrect argument number");
		ft_putendl("usage : ./RT scene.rt list.host");
		return (1);
	}
	init_param(&param, argv[1]);
	raytracer(&param, 4);
	expose_hook(&param);
	mlx_expose_hook(param.env.win, expose_hook, &param);
	mlx_key_hook(param.env.win, key_hook, &param);
	mlx_loop(param.env.mlx);
	return (0);
}
