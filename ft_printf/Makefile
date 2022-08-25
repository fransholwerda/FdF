# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fholwerd <fholwerd@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/09 13:30:24 by fholwerd      #+#    #+#                  #
#    Updated: 2022/08/25 13:45:34 by fholwerd      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC_CONVERSIONS = srcs/conversions/convert_c.c \
	srcs/conversions/convert_s.c \
	srcs/conversions/convert_p.c \
	srcs/conversions/convert_di.c \
	srcs/conversions/convert_u.c \
	srcs/conversions/convert_hex.c
SRC_UTILITIES = srcs/utilities/ft_strlen.c \
	srcs/utilities/ft_putchar.c
SRCS = srcs/ft_printf.c $(SRC_CONVERSIONS) $(SRC_UTILITIES)
SRCS_BONUS =
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
HEADERS = incs/ft_printf.h
CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
OBJ_FILES = $(OBJS) $(OBJS_BONUS)
else
OBJ_FILES = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rc $@ $^

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) -o $@ $<

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
