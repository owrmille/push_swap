NAME        = push_swap
LIBFT       = ./libft/libft/libft.a
LIBFT_DIR   = ./libft/libft

CC          = cc
CFLAGS      = -g -Wextra -Werror -Wall

SRCS        = ./src/temp.c \
			./src/ft_atol_for_nums.c \
            ./src/check_utils.c \
			./src/check_utils_2.c \
			./src/check_utils_3.c \
			./src/node_utils.c \
			./src/memory_utils.c \
			./src/swap.c \
			./src/rotate.c \
			./src/reverse_rotate.c \
			./src/push.c \
			./src/sort_three_nodes.c \
			./src/init_nodes.c \
			./src/stack_utils.c \
			./src/rotate_to_top.c \
			./src/sort.c \
			./src/push_swap.c 

OBJS        = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	@echo "Building $(NAME)..."
	@echo "Checking libft submodule..."
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
        echo "Initializing libft submodule..."; \
        git submodule update --init --recursive libft; \
    else \
        echo "Updating libft submodule..."; \
        git submodule update --recursive libft; \
    fi
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

clean:
	@echo "Cleaning up..."
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
