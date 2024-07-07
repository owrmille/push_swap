#include "push_swap.h"

void	rotate_stacks(t_node **stack_a, t_node **stack_b, t_node *cheapest)
{
	int	cheapest_associate;

	cheapest_associate = cheapest->associate;
	while ((*stack_a)->nbr != cheapest_associate
		&& (*stack_b)->nbr != cheapest->nbr)
	{
		rr(stack_a, stack_b);
	}
	set_indices(stack_a, stack_b);
}

void	rev_rotate_stacks(t_node **stack_a, t_node **stack_b, t_node *cheapest)
{
	int	cheapest_associate;

	cheapest_associate = cheapest->associate;
	while ((*stack_a)->nbr != cheapest_associate
		&& (*stack_b)->nbr != cheapest->nbr)
	{
		rrr(stack_a, stack_b);
	}
	set_indices(stack_a, stack_b);
}

void	rearrange_nodes(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest_node;
	t_node	*associate;

	cheapest_node = find_cheapest_node(*stack_b);
	associate = find_associate_node(cheapest_node, *stack_a);
	if (cheapest_node->top_half == 1
		&& associate->top_half == 1)
		rotate_stacks(stack_a, stack_b, cheapest_node);
	else if (cheapest_node->top_half == 0
		&& associate->top_half == 0)
		rev_rotate_stacks(stack_a, stack_b, cheapest_node);
	rotate_cheapest_to_top_b(stack_b, cheapest_node);
	rotate_cheapest_to_top_a(stack_a, associate);
	pa(stack_a, stack_b);
}

void	sort(int size, t_node **stack_a, t_node **stack_b)
{
	if (is_stack_sorted(*stack_a))
		return ;
	if (size == 3)
		sort_three_nodes(stack_a);
	else
	{
		while (size > 3)
		{
			pb(stack_a, stack_b);
			size--;
		}
		sort_three_nodes(stack_a);
		while (*stack_b)
		{
			// ft_printf("\n-----------CYCLE INFO (before)----------");
			// ft_printf("\nA:\n");
			// print_stack(*stack_a);
			// ft_printf("\nB:\n");
			// print_stack(*stack_b);
			// ft_printf("\n");
			// ft_printf("\nA:\n");
			// print_info(*stack_a);
			// ft_printf("\nB:\n");
			// print_info(*stack_b);
			init_nodes(stack_a, stack_b);
			rearrange_nodes(stack_a, stack_b);
			// ft_printf("\n-----------CYCLE INFO (after)----------");
			// ft_printf("\nA:\n");
			// print_stack(*stack_a);
			// ft_printf("\nB:\n");
			// print_stack(*stack_b);
			// ft_printf("\n");
			// ft_printf("\nA:\n");
			// print_info(*stack_a);
			// ft_printf("\nB:\n");
			// print_info(*stack_b);
		}
		set_indices(stack_a, stack_b);
		rotate_smallest_to_top(stack_a);
	}
}
