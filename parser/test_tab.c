#include "../raytracer.h"

int	test_tab(char **tab, int s_i)
{
	int		i;
	int		j;

	i = 0;
	while (i < s_i)
	{
		j = ft_strlen(tab[i]) - 1;
		while (j >= 0 && ft_isdigit(tab[i][j]))
			j--;
		while (j >= 0 && tab[i][j] == '-')
			j--;
		if (j >= 0)
			return (0);
		i++;
	}
	j = 0;
	while (tab[s_i][j] != '\0')
	{
		if (!ft_isdigit(tab[s_i][j]) && tab[s_i][j] < 'a' && tab[s_i][j] > 'f')
			return (0);
		j++;
	}
	return (1);
}