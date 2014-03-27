#include "raytracer.h"
#include "mesh_struct.h"

void		v_sub(double *dest, double *v1, double *v2)
{
	dest[0] = v1[0] - v2[0];
	dest[1]= v1[1] - v2[1];
	dest[2] = v1[2] - v2[2];
}

double	v_dot(double *v1, double *v2)
{
	return (fabs(v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]));
}

void		v_cross(double *dest, double *v1, double *v2)
{
	dest[0] = v1[1] * v2[2] - v1[2] * v2[1];
	dest[1] = v1[2] * v2[0] - v1[0] * v2[2];
	dest[2] = v1[0] * v2[1] - v1[1] * v2[0];
}
