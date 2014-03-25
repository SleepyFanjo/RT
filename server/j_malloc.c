#include "../includes/network.h"

void		*j_malloc(size_t size)
{
	void	*ret;

	if ((ret = malloc(size)) == NULL)
	{
		if ((ret = malloc(size)) == NULL)
		{
			ft_printf("%rError: Can't malloc\n");
			exit(1);
		}
	}
	return (ret);
}
