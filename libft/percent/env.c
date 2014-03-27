/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 17:04:24 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 15:12:55 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_percent.h"

void		setenv_percent(void)
{
	static struct termios	backup;
	static struct termios	term;
	char					*name_term;
	static int				first = 1;

	if (first)
	{
		first = 0;
		tcgetattr(0, &backup);
		if ((name_term = getenv("TERM")) == NULL)
			return ;
		if (tgetent(NULL, name_term) == ERR)
			return ;
		if (tcgetattr(0, &term) == -1)
			return ;
		term.c_lflag &= ~(ICANON);
		term.c_lflag &= ~(ECHO);
		term.c_lflag &= ~(ISIG);
		term.c_cc[VMIN] = 1;
		term.c_cc[VTIME] = 0;
		tcsetattr(0, TCSADRAIN, &term);
	}
	else
		tcsetattr(0, 0, &backup);
}
