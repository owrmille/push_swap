#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <limits.h>
# include "./libft/libft/libft.h"

typedef	struct s_node
{
	int	nbr;
	int	idx;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

/* temp.c - for me, delete or comment later */
void print_stack(t_node *head);

/* ft_atoi_for_nums.c */
long	ft_atol_for_nums(const char	*str);

/* check_utils.c */
void	print_error();
int	check_nums(int argc, char **argv, t_node **stack_a);
int check_args(int argc, char **argv, t_node **stack_a);
int check_str(char **argv, t_node **stack_a);
int check_doubles(t_node *stack, int number);

/* node_utils.c */
t_node	*find_last_node(t_node *stack);
void	append_node(t_node **stack_a, int number);

# endif