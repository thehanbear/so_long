NAME = so_long

LIBFT = ./libft/libft.a

MLX42 = ./MLX42/build/libmlx42.a

SRCS = main.c about_map.c \

HEADER = so_long.h

CFLAGS = -Wall -Wextra -Werror -g

MLX42FLAGS = -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

all: ${NAME}

${NAME}: ${SRCS} $(LIBFT) $(MLX42)
	cc $(CFLAGS) $^ -framework Cocoa -framework OpenGL -framework IOKit -o $@ $(LIBFT) $(MLX42) $(MLX42FLAGS)

$(LIBFT):
	make -C libft/

$(MLX42):
	cd MLX42 && cmake -B build
	cd MLX42 && cmake --build build -j4
	make -C MLX42/build -j4

clean:
	make clean -C libft
	make clean -C MLX42/build
	rm -rf *.dSYM
	rm -rf *.DS_Store
	rm -rf *.vscode

fclean: clean
	rm -f ${NAME} ${NAME_BONUS}
	make fclean -C libft
	make clean -C MLX42/build

re: fclean all

.PHONY: all clean fclean re