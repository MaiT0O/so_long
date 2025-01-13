# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 13:27:10 by ebansse           #+#    #+#              #
#    Updated: 2025/01/13 15:35:06 by ebansse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = -I/usr/include -Imlx -Ilibft

MLX_LD_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm -lz -Llibft -l:libft.a

CFLAGS	= -Wall -Wextra -Werror

CC = gcc -g

NAME = so_long

SRCS = main.c hook.c map.c map2.c render_move.c img_utils.c img_utils2.c

OBJS = ${SRCS:.c=.o}

all : ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

$(NAME): make_libs $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(MLX_LD_FLAGS) -o $(NAME)

make_libs:
	make -C mlx
	make -C libft

clean :
	make -C mlx clean
	make -C libft clean
	rm -f ${OBJS}

fclean : clean
	make -C mlx clean
	make -C libft fclean
	rm -f ${NAME}

re : fclean all