NAME        = push_swap
LIBFT       = ./libft/libft/libft.a
LIBFT_DIR   = ./libft/libft

CC          = cc
CFLAGS      = -g -Wextra -Werror -Wall

SRCS        = push_swap.c \
            utils.c \
            ft_atoi_for_nums.c

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
