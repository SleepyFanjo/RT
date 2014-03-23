#include "light.h"

static int		final_color(int *color, double light)
{
	int		ret;
	int		pop[3];

	if (light > 1)
		light = 1;
	if (color == NULL)
		return (0);
	pop[0] = color[0] * light;
	pop[1] = color[1] * light;
	pop[2] = color[2] * light;
	ret = pop[0] + 256 * pop[1]	+ 256 * 256 * pop[2];
	return (ret);
}

int			calc_color_end(t_param *param, t_info *info)
{
	calc_reflex(param, info);
	calc_light(param, info, param->spot);
	return (final_color(info->color, info->light));
}
