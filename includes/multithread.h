#ifndef MULTITHREAD_H
# define MULTITHREAD_H

# include "raytracer.h"
# include <ft_printf.h>
# include <pthread.h>

t_list		*get_thread(t_param *param, t_inf_exec *inf, int *end, int *start);
int			print_last_line(t_thread *th, t_limit *l);
int			print_first_line(t_thread *th, t_limit *l);
int			print_middle(t_thread *th, t_limit *l);
int			one_line(t_thread *th, t_limit *l);
t_list		*get_thread_lst(t_limit *limit, t_param *p, int id);
t_list		*get_lst_thread(t_param *p, int *i_e, int step);
int			ft_min(int nb1, int nb2);
int			ft_max(int nb1, int nb2);

#endif
