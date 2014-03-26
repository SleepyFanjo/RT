#include "../includes/client.h"

int		my_mlx_get_color_value(int color, int *decrgb, int depth)
{
	XColor		xc;

	if (depth >= 24)
		return (color);
	xc.red = (color >> 8) & 0xFF00;
	xc.green = color & 0xFF00;
	xc.blue = (color << 8) & 0xFF00;
	xc.pixel = ((xc.red >> (16 - decrgb[1])) << decrgb[0])
		+ ((xc.green >> (16 - decrgb[3])) << decrgb[2])
		+ ((xc.blue >> (16 - decrgb[5])) << decrgb[4]);
	return (xc.pixel);
}
