# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 12:04:58 by vwatrelo          #+#    #+#              #
#    Updated: 2014/03/18 13:35:14 by qchevrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang
FLAGS=-Wall -Wextra -Werror
NAME=libft.a
INCLUDES=-I includes/
LIB=libft_core/libft_core.a \
	list/libft_list.a \
	percent/libft_print_percent.a
#ft_printf/libft_printf.a \


.PHONY: clean fclean all re

all: $(NAME)

$(NAME): libft

libft: $(LIB)
	$(foreach var, $(LIB), mv $(var) $(notdir $(var)) ;)

##ft_printf/libft_printf.a:
##	(cd ft_printf && $(MAKE))

list/libft_list.a:
	(cd list && $(MAKE))

libft_core/libft_core.a:
	(cd libft_core && $(MAKE))

percent/libft_print_percent.a:
	(cd percent && $(MAKE))

clean:
	(cd libft_core && $(MAKE) clean)
##	(cd ft_printf && $(MAKE) clean)
	(cd list && $(MAKE) clean)
	(cd percent && $(MAKE) clean)

fclean: clean
	rm -f $(notdir $(LIB))

re: fclean all
