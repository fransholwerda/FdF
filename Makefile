# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fholwerd <fholwerd@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/01 12:50:34 by fholwerd      #+#    #+#                  #
#    Updated: 2022/09/08 12:15:32 by fholwerd      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ROOT	= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
NAME	= fdf
SRC		=	$(wildcard $(ROOT)src/*.c) \
			$(wildcard $(ROOT)gnl/*.c)
OBJ		= $(SRC:.c=.o)
INCLUDE	= -I$(ROOT)MLX42/include/MLX42 \
			-I$(ROOT)include \
			-I$(ROOT)libft \
			-I$(ROOT)gnl
LIB		= $(ROOT)MLX42/libmlx42.a \
			$(ROOT)libft/libft.a
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

$(NAME): $(OBJ)
	make libs -C $(ROOT)
	$(CC) $(OBJ) $(LIB) $(INCLUDE) -lglfw -L "/Users/fholwerd/.brew/opt/glfw/lib/" -o $(NAME)

libs:
	make -C $(ROOT)MLX42
	make -C $(ROOT)libft

clean:
	rm -f $(OBJ)
	make clean -C MLX42
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f MLX42/libmlx42.a
	rm -f libft/libft.a

re: fclean all

.PHONY: all libs clean fclean re
