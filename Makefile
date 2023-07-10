# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: valentin <valentin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 19:33:03 by valentin          #+#    #+#              #
#    Updated: 2023/07/10 19:56:53 by valentin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC = main.c main_utils.c map_check.c free.c get_file_input.c

OBJ = $(SRC:.c=.o)

CFLAGS = -g -Wall -Werror -Wextra

CC = cc

RM = rm -f

MLX_PATH = mlx/

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS = -lXext -lX11 -lm -lpthread -ldl -fPIE

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

.PHONY: all clean fclean re

all: comp $(NAME)

.c.o:
	$(CC) $(CFLAGS) -g -c $< -o $(<:.c=.o)

comp:
	@echo $(B)
	make -C $(LIBFT_PATH) all
	@echo $(B)
	make -C $(MLX_PATH) all

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) $(MLX_FLAGS) $(LIBFT_LIB) -o $(NAME)

clean:
	@$(RM) $(OBJ)
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_PATH) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@make -C $(MLX_PATH) fclean

re: fclean all