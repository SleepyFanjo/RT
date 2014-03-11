#ifndef MULTITHREAD_H
# define MULTITHREAD_H

# include "raytracer.h"
# include "libft/includes/ft_printf.h"
# include <pthread.h>

# define W 1024
# define J 1024

t_list			*get_thread(t_param *param, int nb_t, int nb_t_tot);

#endif
