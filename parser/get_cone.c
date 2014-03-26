#include "raytracer.h"

static void	set_cone(t_cone *cone, char **tab)
{
	cone->pos.x = ft_atoi(tab[0]);
	cone->pos.y = ft_atoi(tab[1]);
	cone->pos.z = ft_atoi(tab[2]);
	cone->rot.x = ft_atoi(tab[3]);
	cone->rot.y = ft_atoi(tab[4]);
	cone->rot.z = ft_atoi(tab[5]);
	cone->alpha = ft_atoi(tab[6]);
	cone->mat.shine = ft_atoi(tab[7]) / 100.0;
	cone->mat.reflex = ft_atoi(tab[8]) / 100.0;
	cone->mat.med_in = ft_atoi(tab[9]) / 100.0;
	cone->mat.refrax = ft_atoi(tab[10]) / 100.0;
	cone->mat.trans = ft_atoi(tab[11]) / 100.0;
	cone->mat.texture = ft_atoi(tab[12]);
}

int			get_cone(t_obj *obj, char *line)
{
	char		**tab;
	t_cone		*cone;

	if ((tab = ft_strsplit(line, ' ')) == NULL)
	{
		ft_printf("%rAllocation Fail: ");
		return (-1);
	}
	if (get_size_tab(tab) != 14)
	{
		ft_printf("%rCone has no 14 param(%d): ", get_size_tab(tab));
		return (-1);
	}
	if (!test_tab(tab, 13))
		return (-1);
	if ((cone = (t_cone *)malloc(sizeof(t_cone))) == NULL)
		ft_printf("%rAllocation Fail: ");
	if ((cone->color = get_color(tab[13])) == NULL)
	{
		ft_printf("%rAllocation Fail: ");
		return (-1);
	}
	set_cone(cone, tab);
	calc_matrix((void *)cone, CONE);
	ft_lstadd(&(obj->cone), ft_lstnew(cone, sizeof(t_cone)));
	return (0);
}
