#include "push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*first_node;
	t_node	*last_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first_node = *stack;
	last_node = find_last_node(*stack);

	*stack = first_node->next;
	(*stack)->prev = NULL;
	first_node->next = NULL;
	first_node->prev = last_node;
	last_node->next = first_node;
}

void	ra(t_node	**stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_node	**stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_node	**stack_a, t_node	**stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
