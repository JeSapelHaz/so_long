# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 17:55:40 by hbutt             #+#    #+#              #
#    Updated: 2024/07/05 15:47:34 by hbutt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c \
       check_args.c \
       read_map.c \
       init_map.c \
       display.c \
       display_tiles.c \
       moves.c \
       close.c \
       utils_moves.c \
       utils.c \
       ft_win.c \
       finishable.c \
       get_next_line/get_next_line.c \
       get_next_line/get_next_line_utils.c \
       printf/ft_printf.c \
       printf/ft_format.c \
       printf/utils.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(MLXFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re