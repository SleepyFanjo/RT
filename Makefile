# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/03 12:33:25 by qchevrin          #+#    #+#              #
#    Updated: 2014/03/19 16:42:15 by vwatrelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= clang
CFLAGS= -Wall -Werror -Wextra -g
SRC= main.c \
	 apply_transformation.c \
	 hook.c \
	 init_info.c \
	 inter_sphere.c \
	 limited_sphere.c \
	 inter_plane.c \
	 inter_cylinder.c \
	 inter_cone.c \
	 write_on_img.c \
	 light.c \
	 raythrow.c \
	 parser/get_plan.c \
	 parser/get_spot.c \
	 parser/get_cylinder.c \
	 parser/get_cone.c \
	 parser/spheres.c \
	 parser/init_param.c \
	 parser/get_color.c \
	 parser/ft_hex_atoi.c \
	 parser/parser.c \
	 parser/print_error.c \
	 parser/get_size_tab.c \
	 parser/get_obj.c \
	 parser/test_tab.c \
	 parser/get_cam.c \
	 parser/get_sphere.c \
	 multithread/raytracer.c \
	 multithread/get_thread.c

INCLUDES=-I includes/
OBJ= $(SRC:.c=.o)
NAME= Raytracer
LIB=-L./libft -lft_core -lft_printf -lft_list -L/usr/X11/lib -lmlx -lXext -lX11
DIR_LFT=./libft

.PHONY: clean fclean re all

all: $(NAME)

$(NAME): $(OBJ)
	@(cd $(DIR_LFT) ; make)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $< -I./ -I$(DIR_LFT)/includes -I /usr/X11/include/

clean:
	@(cd $(DIR_LFT) ; make clean)
	rm -rf $(OBJ)

fclean: clean
	@(cd $(DIR_LFT) ; make fclean)
	rm -rf $(NAME)

re: fclean all
