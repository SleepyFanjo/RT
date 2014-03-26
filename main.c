/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 11:17:34 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/26 10:51:12 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int			main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("Error : incorrect argument number");
		ft_putendl("usage : ./RT port");
		return (1);
	}
	ft_listen(ft_atoi(argv[1]));
	return (0);
}
