/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 16:46:21 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/19 18:19:25 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

void			apply_matrix(double *matrix, t_coord *move)
{
	move->x = matrix[0] * move->x + matrix[1] * move->y + matrix[2] * move->z;
	move->y = matrix[4] * move->x + matrix[5] * move->y + matrix[6] * move->z;
	move->z = matrix[8] * move->x + matrix[9] * move->y + matrix[10] * move->z;
}

static void		sub_matrix(double *m4, double *m3, int i, int j)
{
	int		t[4];

	t[TI] = 0;
	while (t[TI] < 4)
	{
		if (t[TI] < i)
			t[ID] = t[TI];
		else if (t[TI] > i)
			t[ID] = t[TI] - 1;
		t[TJ] = 0;
		while (t[TJ] < 4)
		{
			if (t[TJ] < j)
				t[JD] = t[TJ];
			else if (t[TJ] > j)
				t[JD] = t[TJ] - 1;
			if (t[TI] != i && t[TJ] != j)
				m3[t[ID] * 3 + t[JD]] = m4[t[TI] * 4 + t[TJ]];
			t[TJ] = t[TJ] + 1;
		}
		t[TI] = t[TI] + 1;
	}
}

static double	m3_det(double *m)
{
	double	det;

	det = m[0] * (m[4] * m[8] - m[7] * m[5]);
	det = det - m[1] * (m[3] * m[8] - m[6] * m[5]);
	det = det + m[2] * (m[3] * m[7] - m[6] * m[4]);
	return (det);
}

static double	m4_det(double *m)
{
	double	c[3];
	double	*m3;
	int		n;

	m3 = (double *)j_malloc(sizeof(double) * 9);
	c[1] = 0;
	c[2] = 1;
	n = 0;
	while (n < 4)
	{
		sub_matrix(m, m3, 0, n);
		c[0] = m3_det(m3);
		c[1] = c[1] + m[n] * c[0] * c[2];
		c[2] = -c[2];
		n = n + 1;
	}
	free(m3);
	return (c[1]);
}

void			invert_matrix(double *res, double *m)
{
	double	det;
	double	*m3;
	int		c[3];

	det = m4_det(m);
	c[0] = 0;
	m3 = (double *)j_malloc(sizeof(double) * 9);
	while (c[0] < 4)
	{
		c[1] = 0;
		while (c[1] < 4)
		{
			c[2] = 1 - ((c[0] + c[1]) % 2) * 2;
			sub_matrix(m, m3, c[0], c[1]);
			res[c[0] + 4 * c[1]] = (m3_det(m3) * c[2]) / det;
			c[1] = c[1] + 1;
		}
		c[0] = c[0] + 1;
	}
	free(m3);
}
