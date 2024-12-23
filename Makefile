# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksudyn <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 15:24:59 by ksudyn            #+#    #+#              #
#    Updated: 2024/11/26 15:25:02 by ksudyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Definiciones de variables
NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address,leak

# Rutas
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx-linux

#(los archivos fuente.c)
SRCS = src/so_long.c \
       src/ft_utils_mlx.c \
       src/main.c \
       src/map.c \
	   src/ft_move.c\
	   src/ft_utils.c\
	   src/start_close_game.c\
	   src/textures.c\
	   src/validate_map.c\
	   src/dimension.c\
	   src/flood_fill.c\
	   src/accessible.c\

# Archivos objeto
OBJS = $(SRCS:.c=.o)

# Archivos de cabecera
INCLUDES = -I./includes -I./libft -I./minilibx-linux

# Rutas de las bibliotecas
LIBFT_LIB = $(LIBFT_DIR)/libft.a
MLX_LIB = $(MLX_DIR)/libmlx.a

# Incluir X11 y math para MiniLibX
LIBS = -lX11 -lXext -lm

# Regla para compilar el ejecutable
$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) -fPIE -o $(NAME) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) $(LIBS)

# Regla para compilar los archivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# Regla para compilar la librería libft
$(LIBFT_LIB):
	make -C $(LIBFT_DIR) CFLAGS="-Wall -Wextra -Werror -fPIC"

# Regla para compilar la biblioteca mlx
$(MLX_LIB):
	make -C $(MLX_DIR)

# Regla para limpiar archivos temporales
clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

# Regla para eliminar todos los archivos objeto y el ejecutable
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

# Regla para hacer un "make" limpio y luego compilar
re: fclean $(NAME)

# Regla para compilar la librería libft
.PHONY: all clean fclean re
