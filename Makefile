# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/03 12:33:25 by qchevrin          #+#    #+#              #
#    Updated: 2014/03/17 14:34:04 by qchevrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= clang
CFLAGS= -Wall -Werror -Wextra -g
SRC= main.c \
	 apply_transformation.c \
	 fill_param.c \
	 hook.c \
	 init_info.c \
	 inter_sphere.c \
	 raythrow.c \
	 parser/get_cam.c \
	 parser/get_cylinder.c \
	 parser/get_obj.c \
	 parser/get_size_tab.c \
	 parser/get_spot.c \
	 parser/parser.c \
	 parser/print_error.c \
	 parser/test_tab.c \
	 parser/v_get_plan.c \
	 parser/v_get_sphere.c \
	 multithread/get_thread.c \
	 multithread/raytracer.c

INCLUDES=-I includes/
OBJ= $(SRC:.c=.o)
NAME= Raytracer
LIB=-L./libft -lft -L/usr/X11/lib -lmlx -lXext -lX11
DIR_LFT= ./libft

.PHONY: clean fclean re all

all: $(NAME)

$(NAME): $(OBJ)
	@(cd $(DIR_LFT) ; make)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $< -I./ -I$(DIR_LFT)/includes

clean:
	@(cd $(DIR_LFT) ; make clean)
	rm -rf $(OBJ)

fclean: clean
	@(cd $(DIR_LFT) ; make fclean)
	rm -rf $(NAME)

re: fclean all
