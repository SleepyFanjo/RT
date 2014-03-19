/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 16:34:57 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/19 16:46:14 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

static double	mult_line(double *m1, double *m2, int l, int c)
{
	double		result;
	int			i;

	result = 0;
	i = 0;
	while (i < 4)
	{
		result = result + m1[l * 4 + i] * m2[c + i * 4];
		i = i + 1;
	}
	return (result);
}

void			multiply_matrix(double *tot, double *m1, double *m2)
{
	tot[0] = mult_line(m1, m2, 0, 0);
	tot[1] = mult_line(m1, m2, 0, 1);
	tot[2] = mult_line(m1, m2, 0, 2);
	tot[3] = mult_line(m1, m2, 0, 3);
	tot[4] = mult_line(m1, m2, 1, 0);
	tot[5] = mult_line(m1, m2, 1, 1);
	tot[6] = mult_line(m1, m2, 1, 2);
	tot[7] = mult_line(m1, m2, 1, 3);
	tot[8] = mult_line(m1, m2, 2, 0);
	tot[9] = mult_line(m1, m2, 2, 1);
	tot[10] = mult_line(m1, m2, 2, 2);
	tot[11] = mult_line(m1, m2, 2, 3);
	tot[12] = mult_line(m1, m2, 3, 0);
	tot[13] = mult_line(m1, m2, 3, 1);
	tot[14] = mult_line(m1, m2, 3, 2);
	tot[15] = mult_line(m1, m2, 3, 3);
}
