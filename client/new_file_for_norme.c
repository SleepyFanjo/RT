/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file_for_norme.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 10:56:44 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 10:58:07 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

void		new_file_for_norme(int newsockfd, int *status)
{
	close(newsockfd);
	wait(status);
}
