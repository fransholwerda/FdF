# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fholwerd <fholwerd@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/01 12:50:34 by fholwerd      #+#    #+#                  #
#    Updated: 2022/09/07 14:51:13 by fholwerd      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ROOT	= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
NAME	= fdf
SRC		=	$(wildcard $(ROOT)src/*.c) \
			$(wildcard $(ROOT)gnl/*.c)
B_SRC	=
OBJ		= $(SRC:.c=.o)
B_OBJ	= $(B_SRC:.c=.o)
INCLUDE	= -I$(ROOT)MLX42/include/MLX42 \
			-I$(ROOT)include \
			-I$(ROOT)libft \
			-I$(ROOT)gnl
FRWRK	=
LIB		= $(ROOT)MLX42/libmlx42.a \
			$(ROOT)libft/libft.a
CFLAGS	= -Wall -Wextra -Werror

ifdef WITH_BONUS
OBJS = $(OBJ) $(OBJ_BONUS)
else
OBJS = $(OBJ)
endif

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

$(NAME): $(OBJS)
	make libs -C $(ROOT)
	$(CC) $(OBJS) $(LIB) $(INCLUDE) -lglfw -L "/Users/fholwerd/.brew/opt/glfw/lib/" -o $(NAME)

libs:
	make -C $(ROOT)MLX42
	make -C $(ROOT)libft

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	rm -f $(OBJS) $(OBJ_BONUS)
	make clean -C MLX42
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f MLX42/libmlx42.a
	rm -f libft/libft.a

re: fclean all

.PHONY: all libs bonus clean fclean re
