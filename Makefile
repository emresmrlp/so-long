# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 20:08:12 by ysumeral          #+#    #+#              #
#    Updated: 2025/02/08 14:54:50 by ysumeral         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./external/mlx
SRC_DIR = ./src
LIB_DIR = ./external/libft
GNL_DIR = ./external/get_next_line
INC_DIR = ./include
PRINTF_LIB = ./external/ft_printf/libftprintf.a
# MAC: MLX = -L${MLX_DIR} -lmlx -framework OpenGL -framework AppKit
MLX = -L$(MLX_DIR) -lmlx -lX11 -lXext

SRC =   $(SRC_DIR)/main.c \
		$(SRC_DIR)/error.c \
		$(SRC_DIR)/free.c \
		$(SRC_DIR)/move.c \
		$(SRC_DIR)/flood_fill.c \
		$(SRC_DIR)/entities.c \
		$(SRC_DIR)/map.c \
		$(SRC_DIR)/map_size.c \
		$(SRC_DIR)/map_parser.c \
		$(SRC_DIR)/key_hook.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/image.c \
		$(LIB_DIR)/ft_calloc.c \
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
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) ${PRINTF_LIB} $(MLX)

$(SRC_DIR)/main.o: $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/main.c -o $(SRC_DIR)/main.o

$(SRC_DIR)/free.o: $(SRC_DIR)/free.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/free.c -o $(SRC_DIR)/free.o

$(SRC_DIR)/flood_fill.o: $(SRC_DIR)/flood_fill.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/flood_fill.c -o $(SRC_DIR)/flood_fill.o

$(SRC_DIR)/error.o: $(SRC_DIR)/error.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/error.c -o $(SRC_DIR)/error.o

$(SRC_DIR)/move.o: $(SRC_DIR)/move.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/move.c -o $(SRC_DIR)/move.o

$(SRC_DIR)/entities.o: $(SRC_DIR)/entities.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/entities.c -o $(SRC_DIR)/entities.o

$(SRC_DIR)/map.o: $(SRC_DIR)/map.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/map.c -o $(SRC_DIR)/map.o

$(SRC_DIR)/map_size.o: $(SRC_DIR)/map_size.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/map_size.c -o $(SRC_DIR)/map_size.o

$(SRC_DIR)/map_parser.o: $(SRC_DIR)/map_parser.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/map_parser.c -o $(SRC_DIR)/map_parser.o

$(SRC_DIR)/key_hook.o: $(SRC_DIR)/key_hook.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/key_hook.c -o $(SRC_DIR)/key_hook.o

$(SRC_DIR)/init.o: $(SRC_DIR)/init.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/init.c -o $(SRC_DIR)/init.o

$(SRC_DIR)/image.o: $(SRC_DIR)/image.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/image.c -o $(SRC_DIR)/image.o

$(LIB_DIR)/ft_calloc.o: $(LIB_DIR)/ft_calloc.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(LIB_DIR)/ft_calloc.c -o $(LIB_DIR)/ft_calloc.o

$(LIB_DIR)/ft_strlcpy.o: $(LIB_DIR)/ft_strlcpy.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(LIB_DIR)/ft_strlcpy.c -o $(LIB_DIR)/ft_strlcpy.o

$(LIB_DIR)/ft_putstr_fd.o: $(LIB_DIR)/ft_putstr_fd.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(LIB_DIR)/ft_putstr_fd.c -o $(LIB_DIR)/ft_putstr_fd.o

$(LIB_DIR)/ft_strlen.o: $(LIB_DIR)/ft_strlen.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(LIB_DIR)/ft_strlen.c -o $(LIB_DIR)/ft_strlen.o

$(LIB_DIR)/ft_strncmp.o: $(LIB_DIR)/ft_strncmp.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(LIB_DIR)/ft_strncmp.c -o $(LIB_DIR)/ft_strncmp.o

$(LIB_DIR)/ft_strrchr.o: $(LIB_DIR)/ft_strrchr.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(LIB_DIR)/ft_strrchr.c -o $(LIB_DIR)/ft_strrchr.o

$(GNL_DIR)/get_next_line.o: $(GNL_DIR)/get_next_line.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(GNL_DIR)/get_next_line.c -o $(GNL_DIR)/get_next_line.o

$(GNL_DIR)/get_next_line_utils.o: $(GNL_DIR)/get_next_line_utils.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(GNL_DIR)/get_next_line_utils.c -o $(GNL_DIR)/get_next_line_utils.o

clean:
	make clean -C ./external/ft_printf
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./external/ft_printf
	make -C $(MLX_DIR) clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re