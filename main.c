#include "raytracer.h"

int			main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("Error : incorrect argument number");
		ft_putendl("usage : ./RT port");
		return (1);
	}
	ft_listen(ft_atoi(argv[1]));
	return (0);
}
