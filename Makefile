# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 15:24:59 by ksudyn            #+#    #+#              #
#    Updated: 2025/08/08 17:10:34 by ksudyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Definiciones de variables
NAME = so_long
BONUS = so_long_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./includes -I./libft -I./minilibx-linux

# Rutas
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx-linux
LIBFT_LIB = $(LIBFT_DIR)/libft.a
MLX_LIB = $(MLX_DIR)/libmlx.a
LIBS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# Archivos fuente compartidos
SHARED_SRCS = \
	src/so_long.c \
	src/ft_utils_mlx.c \
	src/map.c \
	src/ft_utils.c \
	src/start_close_game.c \
	src/textures.c \
	src/validate_map.c \
	src/dimension.c \
	src/flood_fill.c \
	src/accessible.c \

# Solo obligatorios
MANDATORY_SRCS = \
	src/main.c \
	src/ft_move.c \
	src/draw.c

# Solo bonus
BONUS_SRCS = \
	bonus/main_bonus.c \
	bonus/map_bonus.c \
	bonus/move_bonus.c \
	bonus/start_close_bonus.c\
	bonus/texture_bonus.c

# Archivos objeto
SHARED_OBJS = $(SHARED_SRCS:.c=.o)
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Targets
all: $(NAME)

$(NAME): $(SHARED_OBJS) $(MANDATORY_OBJS) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

bonus: $(BONUS)

$(BONUS): $(SHARED_OBJS) $(BONUS_OBJS) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(MLX_LIB):
	make -C $(MLX_DIR)

clean:
	rm -f $(SHARED_OBJS) $(MANDATORY_OBJS) $(BONUS_OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
