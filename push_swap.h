#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <limits.h>
# include "./libft/libft/libft.h"

/* ft_atoi_for_nums.c */
long	ft_atoi_for_nums(const char	*str);

/* utils.c */
void	print_error();
int	only_nums(int argc, char **argv);
int only_nums_in_args(int argc, char **argv);
int only_nums_in_str(char **argv);

# endif