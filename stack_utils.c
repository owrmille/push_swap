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

int	find_smallest_nbr(t_node *stack)
{
	int	min_nbr;

	min_nbr = INT_MAX;
	while (stack)
	{
		if (stack->nbr < min_nbr)
		{
			min_nbr = stack->nbr;
		}
		stack = stack->next;
	}
	return (min_nbr);
}

// void	set_associate_nodes(t_node **stack_a, t_node **stack_b)
// {
// 	int		smallest_greater_nbr;
// 	t_node	*initial_a;
// 	t_node	*initial_b;

// 	initial_b = *stack_b;
// 	initial_a = *stack_a;
// 	while (*stack_b)
// 	{
// 		smallest_greater_nbr = INT_MAX;
// 		// cur_a = *stack_a;
// 		while (*stack_a)
// 		{
// 			if ((*stack_b)->nbr < (*stack_a)->nbr
// 				&& (*stack_a)->nbr < smallest_greater_nbr)
// 			{
// 				smallest_greater_nbr = (*stack_a)->nbr;
// 			}
// 			(*stack_a) = (*stack_a)->next;
// 		}
// 		*stack_a = initial_a;
// 		if (smallest_greater_nbr == INT_MAX)
// 			(*stack_b)->associate = find_smallest_nbr(*stack_a);
// 		else
// 			(*stack_b)->associate = smallest_greater_nbr;
// 		(*stack_b) = (*stack_b)->next;
// 	}
// 	*stack_b = initial_b;
// }

void	set_associate_nodes(t_node **stack_a, t_node **stack_b)
{
	int		smallest_greater_nbr;
	t_node	*cur_a;
	t_node	*cur_b;

	cur_b = *stack_b;
	while (cur_b)
	{
		smallest_greater_nbr = INT_MAX;
		cur_a = *stack_a;
		while (cur_a)
		{
			if (cur_b->nbr < cur_a->nbr
				&& cur_a->nbr < smallest_greater_nbr)
			{
				smallest_greater_nbr = cur_a->nbr;
			}
			cur_a = cur_a->next;
		}
		if (smallest_greater_nbr == INT_MAX)
			cur_b->associate = find_smallest_nbr(*stack_a);
		else
			cur_b->associate = smallest_greater_nbr;
		cur_b = cur_b->next;
	}
}

void	set_cur_idx(t_node **stack)
{
	int		idx;
	int		size;
	t_node	*cur;

	cur = *stack;
	size = stack_size(cur);
	idx = 0;
	while (cur)
	{
		cur->cur_idx = idx;
		if (idx <= size / 2)
			cur->top_half = 1;
		else
			cur->top_half = 0;
		idx++;
		cur = cur->next;
	}
}

void	set_indices(t_node **stack_a, t_node **stack_b)
{
	set_cur_idx(stack_a);
	set_cur_idx(stack_b);
}

void	init_nodes(t_node **stack_a, t_node **stack_b)
{
	set_associate_nodes(stack_a, stack_b);
	set_indices(stack_a, stack_b);
}
