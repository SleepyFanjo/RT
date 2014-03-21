#include "../raytracer.h"

static void	set_cone(t_cone *cone, char **tab)
{
	cone->pos.x = ft_atoi(tab[0]);
	cone->pos.y = ft_atoi(tab[1]);
	cone->pos.z = ft_atoi(tab[2]);
	cone->rot.x = ft_atoi(tab[3]);
	cone->rot.y = ft_atoi(tab[4]);
	cone->rot.z = ft_atoi(tab[5]);
	cone->alpha = ft_atoi(tab[6]);
	cone->mat.shine = ft_atoi(tab[7]) / 100;
	cone->mat.reflex = ft_atoi(tab[8]) / 100;
	cone->mat.med_in = ft_atoi(tab[9]) / 100;
	cone->mat.refrax = ft_atoi(tab[10]) / 100;
	cone->color = get_color(tab[11]);
}

int			get_cone(t_obj *obj, char *line)
{
	char		**tab;
	int			i;
	t_cone		*cone;

	i = 0;
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		print_error(line, "Allocation Fail");
	if (get_size_tab(tab) != 12)
		print_error(line, "Cone has no five param");
	if (!test_tab(tab, 11))
		print_error(line, "Cone is not ok");
	if ((cone = (t_cone *)malloc(sizeof(t_cone))) == NULL)
		print_error(line, "Allocation Fail");
	if ((cone->color = (int *)malloc(sizeof(int))) == NULL)
		print_error(line, "Allocation Fail\n");
	set_cone(cone, tab);
	ft_lstadd(&(obj->cone), ft_lstnew(cone, sizeof(t_cone)));
	return (0);
}
