#include "../raytracer.h"

static int		cam_test_tab(char **tab, int s_i)
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
	return (1);
}

void			get_cam(t_obj *obj, char *line)
{
	char		**tab;
	int			i;
	t_cam		*plan;

	if (obj->cam != NULL)
		print_error("Cam was already defined\n");
	i = 0;
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		print_error("Allocation Fail");
	if (get_size_tab(tab) != 6)
		print_error("Line \"%s\" has no six param");
	if (!cam_test_tab(tab, 6))
		print_error("Line \"%s\" is not ok");
	if ((plan = (t_cam *)malloc(sizeof(t_cam))) == NULL)
		print_error("Allocation Fail");
	plan->point.x = ft_atoi(tab[0]);
	plan->point.y = ft_atoi(tab[1]);
	plan->point.z = ft_atoi(tab[2]);
	plan->rot[0] = ft_atoi(tab[3]);
	plan->rot[1] = ft_atoi(tab[4]);
	plan->rot[2] = ft_atoi(tab[5]);
	obj->cam = plan;
}
