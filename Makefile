CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./external/mlx
SRC_DIR = ./src
LIB_DIR = ./external/libft
GNL_DIR = ./external/get_next_line
INC_DIR = ./include
MLX = -L${MLX_DIR} -lmlx -framework OpenGL -framework AppKit
# LINUX ICIN: MLX = -L$(MLX_DIR) -lmlx -lX11 -lXext

SRC =   $(SRC_DIR)/main.c \
		$(SRC_DIR)/map.c \
		$(SRC_DIR)/map_size.c \
		$(SRC_DIR)/map_parser.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/free.c \
		$(SRC_DIR)/error.c \
		$(LIB_DIR)/ft_calloc.c \
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
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX)

$(SRC_DIR)/main.o: $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/main.c -o $(SRC_DIR)/main.o

$(SRC_DIR)/map.o: $(SRC_DIR)/map.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/map.c -o $(SRC_DIR)/map.o

$(SRC_DIR)/map_size.o: $(SRC_DIR)/map_size.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/map_size.c -o $(SRC_DIR)/map_size.o

$(SRC_DIR)/map_parser.o: $(SRC_DIR)/map_parser.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/map_parser.c -o $(SRC_DIR)/map_parser.o

$(SRC_DIR)/init.o: $(SRC_DIR)/init.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/init.c -o $(SRC_DIR)/init.o

$(SRC_DIR)/free.o: $(SRC_DIR)/free.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/free.c -o $(SRC_DIR)/free.o

$(SRC_DIR)/error.o: $(SRC_DIR)/error.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/error.c -o $(SRC_DIR)/error.o

$(LIB_DIR)/ft_calloc.o: $(LIB_DIR)/ft_calloc.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(LIB_DIR)/ft_calloc.c -o $(LIB_DIR)/ft_calloc.o

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
	make -C $(MLX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re