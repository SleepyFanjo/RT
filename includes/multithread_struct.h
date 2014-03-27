/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:58:47 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 14:59:45 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTITHREAD_STRUCT_H
# define MULTITHREAD_STRUCT_H

# include <pthread.h>
# include "struct.h"
# include "raytracer.h"

typedef struct		s_limit
{
	int				s_i;
	int				s_j;
	int				e_i;
	int				e_j;
}					t_limit;

typedef struct		s_thread
{
	pthread_t		th;
	t_limit			*limit;
	t_param			*p;
	int				id;
}					t_thread;

int					raythrow(t_thread *thread);
#endif
