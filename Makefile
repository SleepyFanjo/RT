# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/03 12:33:25 by qchevrin          #+#    #+#              #
#    Updated: 2014/03/19 10:37:02 by vwatrelo         ###   ########.fr        #
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
	 raythrow.c \
	 parser/fill_plan_list.c \
	 parser/fill_spot_list.c \
	 parser/fill_cylinder_list.c \
	 parser/fill_cone_list.c \
	 parser/init_cam.c \
	 parser/spheres.c \
	 parser/init_param.c \
	 parser/get_color.c \
	 parser/ft_hex_atoi.c \
	 multithread/raytracer.c

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
	$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $< -I./ -I$(DIR_LFT)/includes

clean:
	@(cd $(DIR_LFT) ; make clean)
	rm -rf $(OBJ)

fclean: clean
	@(cd $(DIR_LFT) ; make fclean)
	rm -rf $(NAME)

re: fclean all
