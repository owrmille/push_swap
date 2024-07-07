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

int	is_stack_sorted(t_node *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
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

void	find_cur_idx(t_node **stack)
{
	int		idx;
	int		size;
	t_node	*cur;

	cur = *stack;
	size = stack_size(cur);
	idx = 0;
	if (stack == NULL)
		return ;
	while (cur)
	{
		if (idx <= size / 2)
			cur->top_half = 1;
		else
			cur->top_half = 0;
		cur->cur_idx = idx;
		cur = cur->next;
		idx++;
	}
}
