# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/03 12:33:25 by qchevrin          #+#    #+#              #
#    Updated: 2014/03/22 15:41:16 by vwatrelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= clang
CFLAGS= -Wall -Werror -Wextra -g
SRC= main_serv.c \
	 get_cl_th.c \
	 get_stage.c \
	 get_lst_cl.c \
	 send_stage.c \
	 send_mess.c \
	 send_inf_calc.c

INCLUDES=-I../ -I./ -I../../ -I../../libft/includes
OBJ= $(SRC:.c=.o)
NAME=Server
LIB=-L../../libft -lft_core -lft_list -L/usr/X11/lib -lmlx -lXext -lX11 -lm -lpthread
DIR_LFT=../../libft

.PHONY: clean fclean re all
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	(cd $(DIR_LFT) ; make)
	$(CC) -o $(NAME) $(OBJ) $(LIB)
	echo "\t\xF0\x9F\x8F\x81   Compiling \033[35m$(NAME) \033[0mDONE!"

%.o: %.c
	echo "\t\xF0\x9F\x94\xA7   Building \033[34m $@ \033[0m"
	$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $< -I./ -I$(DIR_LFT)/includes -I /usr/X11/include/

clean:
	echo "\t\xF0\x9F\x92\xA3   Cleaning"
	(cd $(DIR_LFT) ; make clean)
	rm -rf $(OBJ)

fclean: clean
	echo "\t\xF0\x9F\x9A\xBD   Full Clean"
	(cd $(DIR_LFT) ; make fclean)
	rm -rf $(NAME)

re: fclean all
