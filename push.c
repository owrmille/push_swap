#include "push_swap.h"

void	push(t_node **stack_from, t_node **stack_to)
{
	t_node	*first_node_from;
	t_node	*second_node_from;
	t_node	*first_node_to;

	if (stack_from == NULL || *stack_from == NULL)
		return ;
	first_node_from = *stack_from;
	second_node_from = first_node_from->next;
	first_node_to = *stack_to;
	*stack_from = second_node_from;
	if (second_node_from != NULL)
		second_node_from->prev = NULL;
	*stack_to = first_node_from;
	(*stack_to)->prev = NULL;
	(*stack_to)->next = first_node_to;
	if (first_node_to != NULL)
		first_node_to->prev = *stack_to;
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
