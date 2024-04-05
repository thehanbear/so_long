# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlee-sun <hlee-sun@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 14:09:24 by hlee-sun          #+#    #+#              #
#    Updated: 2024/03/19 14:36:43 by hlee-sun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

LIBFT = ./libft/libft.a

MLX42 = ./MLX42/build/libmlx42.a

MLX42FLAGS = -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

SRCS = main.c map.c map_utils.c \
		utils.c error_free.c mlx.c \
		moves.c player.c

SRCS_BONUS = ./bonus/main_bonus.c ./bonus/map_bonus.c \
			./bonus/error_free_bonus.c ./bonus/player_bonus.c \
            ./bonus/utils_bonus.c ./bonus/moves_bonus.c \
			./bonus/map_utils_bonus.c ./bonus/enemy_bonus.c \
			./bonus/mlx_bonus.c 

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT) $(MLX42)
	@cc $(CFLAGS) $^ -o $@ $(LIBFT) $(MLX42) $(MLX42FLAGS)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(SRCS_BONUS) $(LIBFT) $(MLX42)
	@cc $(CFLAGS) $^ -o $@ $(LIBFT) $(MLX42) $(MLX42FLAGS)

$(LIBFT):
	@make -C libft/

$(MLX42): 
	@cd MLX42 && cmake -B build
	@cd MLX42 && cmake --build build -j4
	@make -C MLX42/build -j4

clean:
	@make clean -C libft
	@make clean -C MLX42/build
	@rm -rf *.dSYM
	@rm -rf *.DS_Store

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C libft
	@make clean -C MLX42/build

re: fclean all

bonus_re: fclean bonus

.PHONY: all clean fclean bonus re bonus_re
