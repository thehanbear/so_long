
# NAME	:= Game
# CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
# LIBMLX	:= ./MLX42

# HEADERS	:= -I ./include -I $(LIBMLX)/include
# LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
# SRCS	:= main.c $(shell find ./src -iname "*.c")
# OBJS	:= ${SRCS:.c=.o}

# all: libmlx $(NAME)

# libmlx:
# 	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# %.o: %.c
# 	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

# $(NAME): $(OBJS)
# 	@$(CC) $(OBJS) $(LIBS) $(HEADERS) libmlx42.a -Iinclude -lglfw -o $(NAME)

# clean:
# 	@rm -rf $(OBJS)
# 	@rm -rf $(LIBMLX)/build

# fclean: clean
# 	@rm -rf $(NAME)

# re: clean all

# .PHONY: all, clean, fclean, re, libmlx


# NAME = so_long
# SRCS = main.c
# OBJS= $(SRCS:.c=.o)
# CC = cc
# # HEADER = so_long.h
# FLAGS = -Wall -Wextra -Werror -g
# MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit

# all:$(NAME)

# $(NAME):$(OBJS)
# 	make -C libft all
# 	$(CC) $(FLAGS) $(OBJS) ./libft/libft.a $(MLX_FLAGS) -o $(NAME) 

# $(OBJS):$(SRCS)
# 	$(CC) -c $(FLAGS) $(SRCS)

# clean:
# 		rm -rf $(OBJS)
# 		make -C libft clean

# fclean:clean
# 		rm -rf $(NAME)
# 		rm -rf libft/libft.a

# re: fclean clean all

# .PHONY: all clean fclean re

NAME = so_long

LIBFT = ./libft/libft.a

MLX42 = ./MLX42/build/libmlx42.a

SRCS = main.c \

CFLAGS = -g -Wall -Wextra -Werror

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

fclean: clean
	rm -f ${NAME} ${NAME_BONUS}
	make fclean -C libft
	make clean -C MLX42/build

re: fclean all

.PHONY: all clean fclean re