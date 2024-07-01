#include "push_swap.h"

int	stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

void	set_associate_nodes(t_node **stack_a, t_node **stack_b)
{
	int		smallest_greater_nbr;
	t_node	*cur_a;

	smallest_greater_nbr = INT_MAX;
	cur_a = *stack_a;
	while (*stack_b)
	{
		while (cur_a)
		{
			if ((*stack_b)->nbr < (*stack_a)->nbr 
				&& (*stack_a)->nbr < smallest_greater_nbr)
			{
				smallest_greater_nbr = (*stack_a)->nbr;
				cur_a = cur_a->next;
			}
		}
	}
}

void	init_nodes(t_node **stack_a, t_node **stack_b)
{
	set_associate_nodes(stack_a, stack_b);
}
