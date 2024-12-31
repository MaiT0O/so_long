# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 13:27:10 by ebansse           #+#    #+#              #
#    Updated: 2024/12/23 16:27:10 by ebansse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = -I/usr/include -Imlx -Ilibft

MLX_LD_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm -lz -Llibft -l:libft.a

CFLAGS	= -Wall -Wextra -Werror -g

CC = gcc

NAME = so_long

SRCS = main.c hook.c map.c map2.c display.c

OBJS = ${SRCS:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(MLX_LD_FLAGS) -o $(NAME)

all : ${NAME}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all