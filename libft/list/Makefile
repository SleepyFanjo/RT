# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 12:04:58 by vwatrelo          #+#    #+#              #
#    Updated: 2014/03/19 19:24:26 by lredoban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang
FLAGS=-Wall -Wextra -Werror -O3
NAME=libft_list.a
INCLUDES=-I ../includes
SRC=ft_lstadd.c \
	ft_lstdel.c \
	ft_lstiter.c \
	ft_lstdelone.c \
	ft_lstnew.c \
	ft_lstpop.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): libft

libft: $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS) $(INCLUDES)

.PHONY: clean mrproper

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
