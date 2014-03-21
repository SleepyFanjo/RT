#ifndef MULTITHREAD_STRUCT_H
# define MULTITHREAD_STRUCT_H

# include <pthread.h>
# include "raytracer.h"

typedef struct	s_limit
{
	int			s_i;
	int			s_j;
	int			e_i;
	int			e_j;
}				t_limit;

typedef struct		s_thread
{
	pthread_t		th;
	t_limit			*limit;
	t_param			*p;
	int				id;
}					t_thread;

#endif
