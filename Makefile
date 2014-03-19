# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/03 12:33:25 by qchevrin          #+#    #+#              #
#    Updated: 2014/03/19 19:22:51 by lredoban         ###   ########.fr        #
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
	 calc_normal.c \
	 vec_normal.c \
	 raythrow.c \
	 parser/fill_plan_list.c \
	 parser/fill_spot_list.c \
	 parser/fill_cylinder_list.c \
	 parser/fill_cone_list.c \
	 parser/init_cam.c \
	 parser/spheres.c \
	 parser/init_param.c \
	 matrix/apply_matrix.c \
	 matrix/fill_matrix.c \
	 matrix/multiply_matrix.c \
	 multithread/raytracer.c

INCLUDES=-I./includes/ -I./
INC=multithread.h \
	multithread_struct.h \
	matrix.h \
	raytracer.h \
	struct.h
OBJ= $(SRC:.c=.o)
NAME= Raytracer
LIB=-L./libft -lft_core -lft_printf -lft_list -L/usr/X11/lib -lmlx -lXext -lX11
DIR_LFT=./libft

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
