/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_malloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 12:06:03 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 12:06:03 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/network.h"

void		*j_malloc(size_t size)
{
	void	*ret;

	if ((ret = malloc(size)) == NULL)
	{
		if ((ret = malloc(size)) == NULL)
		{
			ft_printf("%rError: Can't malloc\n");
			exit(1);
		}
	}
	return (ret);
}
