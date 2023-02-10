# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chales <chales@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 23:05:41 by plopes-c          #+#    #+#              #
#    Updated: 2023/02/10 04:58:57 by chales           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = libft/libft.a

MLX = minilibx/libmlx.a

SRCS = *.c utils/*.c

RM = rm -fr

CFLAGS =

MLX_FLAGS = -Lmlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME):		$(SRCS)
				@make bonus -s -C libft
				@make -s -C minilibx
				@gcc $(CFLAGS) $(SRCS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

clean: 
				@make clean -s -C libft

fclean:			
				@make fclean -s -C libft
				@make clean -s -C minilibx
				@$(RM) $(NAME)
				
re:				fclean $(NAME)

run:			all
				./so_long				