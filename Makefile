# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/03 12:33:25 by qchevrin          #+#    #+#              #
#    Updated: 2014/03/24 19:56:57 by lredoban         ###   ########.fr        #
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
	 light/calc_color.c \
	 light/get_mat.c \
	 light/textures.c \
	 multithread/raytracer.c \
	 multithread/get_thread.c \
	 multithread/print_first_line.c \
	 multithread/one_line.c \
	 multithread/print_middle.c \
	 ui/key1.c \
	 ui/ui.c \
	 ui/save.c \
	 ui/l_printf.c \
	 ui/ft_uitoa.c \
	 ui/ft_hexa.c \
	 ui/ft_num.c \
	 ui/ft_putui.c \
	 ui/clic.c

INCLUDES=-I./ui/ -I./includes/
INC=multithread.h \
	multithread_struct.h \
	matrix.h \
	raytracer.h \
	struct.h \
	ui/ui.h
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
