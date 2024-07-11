NAME = pushswap

SRC_DIR				= src/

SRC = $(SRC_DIR)/push_swap.c $(SRC_DIR)stack_init.c $(SRC_DIR)utils.c $(SRC_DIR)errors.c $(SRC_DIR)rotate.c $(SRC_DIR)swap.c
OBJ := $(SRC:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -Ilibft -Ift_printf

.PHONY: all clean fclean re libft ft_printf

all: libft ft_printf $(NAME)

libft:
	make -C libft

ft_printf:
	make -C ft_printf

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME) -Llibft -lft -Lft_printf -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft
	make fclean -C ft_printf

re: fclean all