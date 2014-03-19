#include "../raytracer.h"

int		one_line(t_thread *th, t_limit *l)
{
	int		i;

	i = l->s_i;
	while (i < l->e_i)
	{
		if (put_pixel_to_img(th->p, l->s_j, i))
			return (-1);
		i++;
	}
	return (0);
}
