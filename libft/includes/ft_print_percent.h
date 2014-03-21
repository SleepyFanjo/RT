/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 16:38:02 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/02/12 17:33:39 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_PERCENT_H
# define FT_PRINT_PERCENT_H

# include "libft.h"
# include <sys/ioctl.h>
# include <curses.h>
# include <term.h>

void		ft_print_percent(int percent);
int			my_tput(int c);
void		setenv_percent(void);

#endif
