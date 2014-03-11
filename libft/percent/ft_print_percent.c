/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 15:26:38 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/02/13 16:07:31 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_percent.h"

static int		place_nb_char(int percent, char *str, int size)
{
	float	i;
	float	nb_char;

	nb_char = 100.0f / (double)(size - 3);
	i = 0;
	while (i * nb_char <= percent)
	{
		str[(int)i] = '=';
		i += 1.0f;
	}
	str[(int)i] = '>';
	i += 1.0f;
	while ((int)i < size)
	{
		str[(int)i] = ' ';
		i += 1.0f;
	}
	return (i);
}

static void		print_str_percent(int percent, char *str)
{
	char	*per_str;

	per_str = ft_itoa(percent);
	if (percent >= 100)
		ft_strcat(str, "done");
	else if (ft_strlen(per_str) == 2)
		ft_strcat(str, per_str);
	else if (ft_strlen(per_str) == 1)
	{
		ft_strcat(str, "0");
		ft_strcat(str, per_str);
	}
}

static int		move_cursor_left(int cur_pos)
{
	char	*res;

	if ((res = tgetstr("le", NULL)) != NULL)
	{
		while (cur_pos > 0)
		{
			tputs(res, 0, my_tput);
			cur_pos--;
		}
	}
	return (cur_pos);
}

void			ft_print_percent(int percent)
{
	struct winsize	w;
	char			*str;
	int				index;
	static int		pos_curs = 0;

	move_cursor_left(pos_curs);
	ioctl(1, TIOCGWINSZ, &w);
	if (w.ws_col < 20)
		return ;
	str = ft_strnew(w.ws_col - 1);
	str[0] = '|';
	ft_putstr("\e[1;30m");
	index = place_nb_char(percent, str + 1, w.ws_col - 10);
	ft_putstr("\e[0m");
	str[index++] = '|';
	str[index++] = '[';
	print_str_percent(percent, str + index);
	index += 2;
	if (percent < 100)
		str[index++] = '%';
	else
		index += 2;
	str[index++] = ']';
	write(1, str, ft_strlen(str));
	pos_curs = ft_strlen(str);
}
