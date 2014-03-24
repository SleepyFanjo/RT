# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/03 12:33:25 by qchevrin          #+#    #+#              #
#    Updated: 2014/03/24 19:49:04 by vwatrelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= clang
CFLAGS= -Wall -Werror -Wextra -g
SRC= main.c \
	 apply_transformation.c \
	 init_info.c \
	 inter_sphere.c \
	 limited_sphere.c \
	 inter_plane.c \
	 inter_cylinder.c \
	 inter_cone.c \
	 write_on_img.c \
	 calc_normal.c \
	 vec_normal.c \
	 raythrow.c \
	 swap_double.c \
	 parser/get_plan.c \
	 parser/get_spot.c \
	 parser/get_cylinder.c \
	 parser/get_cone.c \
	 parser/spheres.c \
	 parser/init_param.c \
	 matrix/apply_matrix.c \
	 matrix/fill_matrix.c \
	 parser/get_color.c \
	 parser/ft_hex_atoi.c \
	 parser/parser.c \
	 parser/print_error.c \
	 parser/get_size_tab.c \
	 parser/get_obj.c \
	 parser/test_tab.c \
	 parser/get_cam.c \
	 parser/get_sphere.c \
	 parser/free_obj_lst.c \
	 light/light.c \
	 light/reflex.c \
	 multithread/raytracer.c \
	 multithread/get_thread.c \
	 multithread/print_first_line.c \
	 multithread/one_line.c \
	 multithread/print_middle.c \
	 client/client.c \
	 client/get_stage.c \
	 client/send_mess.c \
	 client/get_core.c \
	 client/send_stage.c \
	 client/get_value.c \
	 client/get_env.c \
	 client/my_mlx_get_color_value.c \
	 client/compute.c \
	 client/calc_multi_stage.c

INCLUDES=-I./includes/ -I./
INC=multithread.h \
	multithread_struct.h \
	matrix.h \
	raytracer.h \
	struct.h
OBJ= $(SRC:.c=.o)
NAME= Raytracer
LIB=-L./libft -lft_core -lft_list -L/usr/X11/lib -lmlx -lXext -lX11 -lm -lpthread
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
