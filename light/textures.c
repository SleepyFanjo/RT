#include "light.h"

int		*checker_1(t_coord point)
{
	double	tmp1;
	double	tmp2;
	int		*color;

	tmp1 = sin(F_PI / 70.0) * sin((F_PI / 70.0) * point.x);
	tmp2 = sin(F_PI / 70.0) * sin((F_PI / 70.0) * point.z);
	color = (int *)j_malloc(sizeof(int) * 3);
	if ((tmp1 >= 0 && tmp2 >= 0) || (tmp1 < 0 && tmp2 < 0))
		return (init_color());
	color[0] = 255;
	color[1] = 255;
	color[2] = 255;
	return (color);
}

int		*checker_2(t_coord point)
{
	double	tmp1;
	double	tmp2;
	int		*color;

	tmp1 = sin(F_PI / 70.0) * sin((F_PI / 70.0) * point.y);
	tmp2 = sin(F_PI / 70.0) * sin((F_PI / 70.0) * point.z);
	color = (int *)j_malloc(sizeof(int) * 3);
	if ((tmp1 >= 0 && tmp2 >= 0) || (tmp1 < 0 && tmp2 < 0))
		return (init_color());
	color[0] = 255;
	color[1] = 255;
	color[2] = 255;
	return (color);
}

//checker

int		*damer(t_info *info, t_coord point)
{
	int	tmp;

	if ((tmp = get_texture(info)) == 1)
		return (checker_2(point));
//	if (get_texture(info) == 2)
//		return (text_1(info, point));
//	if (get_texture(info) == 3)
//		return (text_2(info, point));
	return (info->color);
}
