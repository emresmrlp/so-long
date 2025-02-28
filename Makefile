# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 20:08:12 by ysumeral          #+#    #+#              #
#    Updated: 2025/02/27 19:10:20 by ysumeral         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = ./src
MLX_DIR = ./external/mlx
LIB_DIR = ./external/libft
GNL_DIR = ./external/get_next_line
INC_DIR = ./include
PRINTF_LIB = ./external/ft_printf/libftprintf.a
MLX = -L$(MLX_DIR) -lmlx -lX11 -lXext
SRC =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/error_handler.c \
		$(SRC_DIR)/memory_free.c \
		$(SRC_DIR)/player_movement.c \
		$(SRC_DIR)/map_handler.c \
		$(SRC_DIR)/map_loader.c \
		$(SRC_DIR)/map_util.c \
		$(SRC_DIR)/map_validator.c \
		$(SRC_DIR)/input_handler.c \
		$(SRC_DIR)/image_handler.c \
		$(SRC_DIR)/image_loader.c \
		$(SRC_DIR)/game_state.c \
		$(SRC_DIR)/game_init.c \
		$(SRC_DIR)/collectible_handler.c \
		$(SRC_DIR)/entity_loader.c \
		$(LIB_DIR)/ft_calloc.c \
		$(LIB_DIR)/ft_strdup.c \
		$(LIB_DIR)/ft_strlcpy.c \
		$(LIB_DIR)/ft_putstr_fd.c \
		$(LIB_DIR)/ft_strncmp.c \
		$(LIB_DIR)/ft_strlen.c \
		$(LIB_DIR)/ft_strrchr.c \
		$(GNL_DIR)/get_next_line.c \
		$(GNL_DIR)/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./external/ft_printf
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -I${INC_DIR} -o $(NAME) $(OBJ) ${PRINTF_LIB} $(MLX)

clean:
	make clean -C ./external/ft_printf
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./external/ft_printf
	make -C $(MLX_DIR) clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re