NAME = push_swap

SRC_DIR = src/

SRC = $(SRC_DIR)push_swap.c
OBJ = $(SRC:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -Ilibft -Ift_printf

LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf

.PHONY: all clean fclean re libft ft_printf

all: $(NAME)

libft:
	$(MAKE) -C $(LIBFT_DIR)

ft_printf:
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): libft ft_printf $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(FT_PRINTF_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(FT_PRINTF_DIR)

re: fclean all

# NAME = push_swap

# SRC_DIR				= src/

# SRC = $(SRC_DIR)/push_swap.c
# OBJ := $(SRC:%.c=%.o)

# CC = gcc
# CFLAGS = -Wall -Wextra -Werror -g
# INCLUDES = -Ilibft -Ift_printf

# .PHONY: all clean fclean re libft ft_printf

# all: libft ft_printf $(NAME)

# libft:
# 	make -C libft

# ft_printf:
# 	make -C ft_printf

# $(NAME): $(OBJ)
# 	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME) -Llibft -lft -Lft_printf -lftprintf

# %.o: %.c
# 	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# clean:
# 	$(RM) $(OBJ)
# 	make clean -C libft
# 	make clean -C ft_printf

# fclean: clean
# 	$(RM) $(NAME)
# 	make fclean -C libft
# 	make fclean -C ft_printf

# re: fclean all