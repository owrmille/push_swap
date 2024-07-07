#include "push_swap.h"

void	set_indices(t_node **stack_a, t_node **stack_b)
{
	find_cur_idx(stack_a);
	find_cur_idx(stack_b);
}

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

void	set_prices(t_node **stack_a, t_node **stack_b)
{
	t_node	*cur;
	t_node	*associate;
	int		size_a;
	int		size_b;

	cur = *stack_b;
	size_a = stack_size(*stack_a);
	size_b = stack_size(*stack_b);
	while (cur)
	{
		cur->price_before_push = cur->cur_idx;
		associate = find_associate_node(cur, *stack_a);
		if (cur->top_half == 0)
			cur->price_before_push = size_b - cur->cur_idx;
		if (associate->top_half == 1)
			cur->price_before_push += associate->cur_idx;
		else
		{
			cur->price_before_push += size_a - associate->cur_idx;
		}
		cur = cur->next;
	}
}

void	set_cheapest_node(t_node **stack_a, t_node **stack_b)
{
	t_node	*cur_b;
	t_node	*cheapest_node;
	int		cheapest;

	(void)stack_a;
	cur_b = *stack_b;
	cheapest = INT_MAX;
	while (cur_b)
	{
		cur_b->cheapest_price = 0;
		if (cur_b->price_before_push < cheapest)
		{
			cheapest = cur_b->price_before_push;
			cheapest_node = cur_b;
		}
		cur_b = cur_b->next;
	}
	cheapest_node->cheapest_price = 1;
}

void	init_nodes(t_node **stack_a, t_node **stack_b)
{
	set_indices(stack_a, stack_b);
	set_associate_nodes(stack_a, stack_b);
	set_prices(stack_a, stack_b);
	set_cheapest_node(stack_a, stack_b);
}
