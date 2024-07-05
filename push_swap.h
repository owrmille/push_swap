#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <limits.h>
# include "./libft/libft/libft.h"

typedef struct s_node
{
	int				nbr;
	int				associate;
	int				cur_idx;
	int				price_before_push;
	int				top_half;
	int				cheapest_price;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* temp.c - for me, delete or comment later */
void	print_stack(t_node *head);
void	print_string_array(char **array);
void	print_associates(t_node *stack);
void	print_info(t_node *stack);

/* ft_atoi_for_nums.c */
long	ft_atol_for_nums(const char	*str);

/* check_utils.c */
void	print_error(void);
int		find_symbol(char *s, char c);
int		check_nums(int argc, char **argv, t_node **stack_a);
int		check_args(int argc, char **argv, t_node **stack_a);
int		check_str(char **argv, t_node **stack_a);
int		check_doubles(t_node *stack, int number);

/* node_utils.c */
t_node	*find_last_node(t_node *stack);
void	append_node(t_node **stack_a, int number);

/* memory_utils.c */
void	free_stack(t_node *stack);
void	free_array(char	**array);

/* swap.c */
void	swap(t_node **stack);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);

/* rotate.c */
void	rotate(t_node **stack);
void	ra(t_node	**stack_a);
void	rb(t_node	**stack_b);
void	rr(t_node	**stack_a, t_node	**stack_b);

/* reverse_rotate.c */
void	reverse_rotate(t_node **stack);
void	rra(t_node	**stack_a);
void	rrb(t_node	**stack_b);
void	rrr(t_node	**stack_a, t_node	**stack_b);

/* push.c */
void	push(t_node **stack_1, t_node **stack_2);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);

/* sort_three_nodes.c */
t_node	*find_max_node(t_node *stack);
void	sort_three_nodes(t_node **stack);

/* sort_utils.c */
int		is_stack_sorted(t_node *stack);

/* stack_utils.c */
int	stack_size(t_node *stack);
int		find_smallest_nbr(t_node *stack);
void	set_associate_nodes(t_node **stack_a, t_node **stack_b);
void	find_cur_idx(t_node **stack);
void	set_indices(t_node **stack_a, t_node **stack_b);
// void	calculate_price(t_node **stack);
void	set_prices(t_node **stack_a, t_node **stack_b);
void	set_cheapest_node(t_node **stack_a, t_node **stack_b);
void	init_nodes(t_node **stack_a, t_node **stack_b);

/* sort.c */
void	rotate_stacks(t_node **stack_a, t_node **stack_b, t_node *cheapest);
void	rev_rotate_stacks(t_node **stack_a, t_node **stack_b, t_node *cheapest);
t_node	*find_cheapest_node(t_node *stack);
t_node	*find_associate_node(t_node *node_b, t_node *stack_a);
void	rotate_cheapest_to_top_a(t_node **stack_a, t_node *cheapest_node);
void	rotate_cheapest_to_top_b(t_node **stack_b, t_node *cheapest_associate);
void	rearrange_nodes(t_node **stack_a, t_node **stack_b);
void	sort(int size, t_node **stack_a, t_node **stack_b);

# endif