# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 17:55:40 by hbutt             #+#    #+#              #
#    Updated: 2024/06/20 18:45:36 by hbutt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c \
			check_args.c \
			read_map.c \
			init_map.c \
			utils.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c
			
OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -f
MLXFLAGS := -Lmlx -lmlx -framework OpenGL -framework AppKit
MLXPATH = ./mlx
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS} $(MLXFLAGS)

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re