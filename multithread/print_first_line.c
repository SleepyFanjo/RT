#include "multithread.h"

int		print_first_line(t_thread *th, t_limit *l)
{
	int		i;

	i = l->s_i;
	while (i < WIDTH)
	{
		if (put_pixel_to_img(th->p, l->s_j, i))
			return (-1);
		i++;
	}
	return (0);
}

int		print_last_line(t_thread *th, t_limit *l)
{
	int		i;

	i = 0;
	while (i < l->e_i)
	{
		if (put_pixel_to_img(th->p, l->e_j - 1, i))
			return (-1);
		i++;
	}
	return (0);
}
