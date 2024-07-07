#include "push_swap.h"

void	rotate_cheapest_to_top_a(t_node **stack_a, t_node *cheapest_associate)
{
	while (*stack_a != cheapest_associate)
	{
		if (cheapest_associate->top_half)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	rotate_cheapest_to_top_b(t_node **stack_b, t_node *cheapest_node)
{
	while (*stack_b != cheapest_node)
	{
		if (cheapest_node->top_half)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

void	rotate_smallest_to_top(t_node **stack_a)
{
	t_node	*smallest_node;

	smallest_node = find_smallest_node(*stack_a);
	if (smallest_node->top_half == 1)
	{
		while ((*stack_a) != smallest_node)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a) != smallest_node)
			rra(stack_a);
	}
}
