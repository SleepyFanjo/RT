#ifndef MULTITHREAD_H
# define MULTITHREAD_H

# include "raytracer.h"
# include "libft/includes/ft_printf.h"
# include <pthread.h>

t_list		*get_thread(t_param *param, t_inf_exec *inf, int *end, int *start);
int			print_last_line(t_thread *th, t_limit *l);
int			print_first_line(t_thread *th, t_limit *l);
int			print_middle(t_thread *th, t_limit *l);
int			one_line(t_thread *th, t_limit *l);

#endif
