/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_inf_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 12:06:48 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 12:06:49 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/network.h"

int		send_inf_calc(t_list *list, t_info_serv *inf, int nb_cl)
{
	t_inf_exec	*exec;
	t_client	*cl;

	exec = j_malloc(sizeof(t_inf_exec));
	bzero(exec, sizeof(t_inf_exec));
	exec->nb_tot_th = nb_cl * inf->nb_th;
	exec->nb_st_th = 0;
	exec->nb_th = inf->nb_th;
	while (list != NULL)
	{
		cl = (t_client *)list->content;
		write(cl->sockfd, exec, sizeof(t_inf_exec));
		exec->nb_st_th += exec->nb_th;
		list = list->next;
	}
	if ((list != NULL) ^ (exec->nb_st_th < exec->nb_tot_th))
		ft_printf("%r#11\n");
	free(exec);
	return (0);
}
