#include "push_swap.h"

void	reverse_rotate(t_node **stack)
{
	t_node	*first_node;
	t_node	*last_node;
	t_node	*second_last_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first_node = *stack;
	last_node = find_last_node(*stack);
	second_last_node = last_node->prev;

	*stack = last_node;
	(*stack)->prev = NULL;
	(*stack)->next = first_node;
	first_node->prev = *stack;
	if (second_last_node != NULL)
		second_last_node->next = NULL;
}

void	rra(t_node	**stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_node	**stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_node	**stack_a, t_node	**stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
