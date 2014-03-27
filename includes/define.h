/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:29:04 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 15:29:06 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define SIZE_FAIL		0
# define SIZE_SUCCES	1
# define STAGE_FAIL		2
# define STAGE_SUCCES	3
# define MOD_CLIENT		0

# define NAME_STAGE		"stage.tmp"
# define NET_BUFF_SIZE	100000
# define LIM_NB_WRITE	10
# define LIM_NB_READ	10
# define START_MODE		1

# define T0			(param->text[0])
# define T1			(param->text[1])
# define T2			(param->text[2])
# define T3			(param->text[3])
# define T4			(param->text[4])
# define T5			(param->text[5])
# define T6			(param->text[6])
# define T7			(param->text[7])
# define T8			(param->text[8])

typedef struct	s_inf_exec
{
	int			nb_th;
	int			nb_tot_th;
	int			nb_st_th;
	int			decrgb[6];
}				t_inf_exec;

#endif
