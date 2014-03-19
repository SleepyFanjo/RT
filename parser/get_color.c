#include "raytracer.h"

int			test_col_str(char *color)
{
	int		i;

	i = 0;
	*color = ft_toupper(*color);
	while (color[i] != '\0'
			&& (ft_isdigit(color[i]) || (color[i] > 'A' && color[i] <= 'F')))
	{
		i++;
		color[i] = ft_toupper(color[i]);
	}
	if (i != 6)
		return (0);
	return (1);
}

int			*get_color(char *color)
{
	int		*tab;

	printf("color: %s\n", color);
	if (!test_col_str(color))
	{
		ft_putstr_fd("Get color fail\n", 2);
		exit(1);
	}
	tab = (int *)j_malloc(sizeof(int) * 3);
	tab[0] = ft_hex_atoi(color);
	tab[1] = ft_hex_atoi(color + 2);
	tab[2] = ft_hex_atoi(color + 4);
	return (tab);
}
