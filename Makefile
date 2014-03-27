# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/03 12:33:25 by qchevrin          #+#    #+#              #
#    Updated: 2014/03/27 07:18:16 by vwatrelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
FLAG=-Wall -Wextra -Werror -g
SRC1=apply_transformation.c \
	 init_info.c \
	 inter_sphere.c \
	 limited_sphere.c \
	 limited_cylinder.c \
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
	 matrix/transformation.c \
	 matrix/calc_matrix.c \
	 parser/get_color.c \
	 parser/ft_hex_atoi.c \
	 parser/parser.c \
	 parser/print_error.c \
	 parser/get_size_tab.c \
	 parser/get_obj.c \
	 parser/test_tab.c \
	 parser/get_cam.c \
	 parser/get_mesh.c \
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
	 client/get_stage.c \
	 client/send_mess.c \
	 client/get_core.c \
	 client/send_stage.c \
	 client/get_value.c \
	 client/get_env.c \
	 client/my_mlx_get_color_value.c \
	 client/compute.c \
	 client/calc_multi_stage.c \
	 client/client.c \
	 mesh/moller.c \
	 mesh/calc_inter_mesh.c \
	 mesh/calc_inter_tri.c \
	 mesh/prequel_inter.c \
	 ft_error.c \
	 main.c

SRC2=server/main_serv.c \
	 server/get_cl_th.c \
	 server/get_stage.c \
	 server/get_lst_cl.c \
	 server/send_stage.c \
	 server/send_mess.c \
	 server/send_inf_calc.c \
	 server/get_cl_stage.c \
	 server/get_value.c \
	 server/init_env.c \
	 server/hook.c \
	 server/textures/get_textures.c \
	 server/send_env.c \
	 server/free_cl.c \
	 client/my_mlx_get_color_value.c \
	 apply_transformation.c \
	 init_info.c \
	 inter_sphere.c \
	 limited_sphere.c \
	 limited_cylinder.c \
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
	 matrix/transformation.c \
	 matrix/calc_matrix.c \
	 parser/get_color.c \
	 parser/ft_hex_atoi.c \
	 parser/parser.c \
	 parser/print_error.c \
	 parser/get_size_tab.c \
	 parser/get_obj.c \
	 parser/test_tab.c \
	 parser/get_cam.c \
	 parser/get_sphere.c \
	 parser/get_mesh.c \
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
	 ui/clic.c \
	 mesh/calc_inter_mesh.c \
	 mesh/calc_inter_tri.c \
	 mesh/prequel_inter.c \
	 mesh/moller.c \
	 ft_error.c \
	 server/calc_img.c

INCLUDES=-I./ui/ -I./includes/ -I./libft/includes/
OBJ1= $(SRC1:.c=.o)
OBJ2= $(SRC2:.c=.o)
NAME1= Exec_client
NAME2= Raytracer
LIB=-L./libft -lft_core -lft_list -L/usr/X11/lib -lmlx -lXext -lX11 -lm -lpthread -I /usr/X11/include/
DIR_LFT=./libft

.PHONY: clean fclean re all

.SILENT:

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1)
	(cd $(DIR_LFT) ; make)
	$(CC) -o $(NAME1) $(OBJ1) $(LIB) $(FLAG)
	echo "\t\xF0\x9F\x8F\x81   Compiling \033[35m$(NAME1) \033[0mDONE!"

$(NAME2): $(OBJ2)
	(cd $(DIR_LFT) ; make)
	$(CC) -o $(NAME2) $(OBJ2) $(LIB) $(FLAG)
	echo "\t\xF0\x9F\x8F\x81   Compiling \033[35m$(NAME2) \033[0mDONE!"

%.o: %.c
	echo "\t\xF0\x9F\x94\xA7   Building \033[34m $@ \033[0m"
#	$(CC) -c $(FLAG) -o $@ $< $(INCLUDES)
	$(CC) -c $(FLAGS)  $(INCLUDES) -o $@ $< $(LIB)

clean:
	echo "\t\xF0\x9F\x92\xA3   Cleaning"
	(cd $(DIR_LFT) ; make clean)
	rm -rf $(OBJ1)
	rm -rf $(OBJ2)

fclean: clean
	echo "\t\xF0\x9F\x9A\xBD   Full Clean"
	(cd $(DIR_LFT) ; make fclean)
	rm -rf $(NAME1)
	rm -rf $(NAME2)

re: fclean all
