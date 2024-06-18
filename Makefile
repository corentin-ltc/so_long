NAME = so_long

SRC_DIR = ./srcs/
OBJ_DIR = ./objs/
LIBFT = ./libft/libft.a
UTILS_DIR = $(SRC_DIR)utils/

CFLAGS = #-Wall -Wextra -Werror
MLXFLAGS = -lm -lX11 -lXext minilibx-linux/libmlx_Linux.a

CC = cc
RM = rm -rf

SRCS = $(wildcard $(SRC_DIR)*.c) $(wildcard $(UTILS_DIR)*.c)
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(CFLAGS) $(MLXFLAGS) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: start all clean fclean re