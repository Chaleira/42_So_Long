# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chales <chales@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 23:05:41 by plopes-c          #+#    #+#              #
#    Updated: 2023/02/27 14:59:06 by chales           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = libft/libft.a

MLX = minilibx/libmlx.a

SRCS =	so_long.c	utils/check.c	utils/map.c		utils/free.c	utils/image.c \
		utils/utils.c	utils/win.c

OBJS = $(SRCS:.c=.o)

RM = rm -fr

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -Lmlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME):		$(OBJS)
				@make bonus -s -C libft
				@gcc $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

clean: 
				$(RM) $(OBJS)
				@make clean -s -C libft

fclean:			clean
				@make fclean -s -C libft
				@$(RM) $(NAME)
				
re:				fclean $(NAME)
