NAME        = push_swap
LIBFT       = ./libft/libft/libft.a
LIBFT_DIR   = ./libft/libft

CC          = cc
CFLAGS      = -g -Wextra -Werror -Wall

SRCS        = temp.c \
			ft_atol_for_nums.c \
            check_utils.c \
			check_utils_2.c \
			check_utils_3.c \
			node_utils.c \
			memory_utils.c \
			swap.c \
			rotate.c \
			reverse_rotate.c \
			push.c \
			sort_three_nodes.c \
			init_nodes.c \
			stack_utils.c \
			rotate_to_top.c \
			sort.c \
			push_swap.c 

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
