#include "../multithread.h"

int		print_middle(t_thread *th, t_limit *l)
{
	int		i;
	int		j;

	j = l->s_j + 1;
	while (j < l->e_j - 1)
	{
		i = 0;
		while (i < WIDTH)
		{
			if (put_pixel_to_img(th->p, j, i))
				return (-1);
			i++;
		}
		j++;
	}
	return (0);
}
