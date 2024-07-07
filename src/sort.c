/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatopchu <iatopchu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 01:21:48 by iatopchu          #+#    #+#             */
/*   Updated: 2024/07/08 01:21:49 by iatopchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	sort_five_nodes(t_node **a, t_node **b)
{
	while (stack_size(*a) > 3)
	{
		init_nodes(a, b);
		rotate_cheapest_to_top_a(a, find_smallest_node(*a));
		pb(a, b);
	}
}

void	sort(int size, t_node **stack_a, t_node **stack_b)
{
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three_nodes(stack_a);
	else
	{
		if (size == 5)
			sort_five_nodes(stack_a, stack_b);
		else
		{
			while (size > 3)
			{
				pb(stack_a, stack_b);
				size--;
			}
		}
		sort_three_nodes(stack_a);
		while (*stack_b)
		{
			init_nodes(stack_a, stack_b);
			rearrange_nodes(stack_a, stack_b);
		}
		set_indices(stack_a, stack_b);
		rotate_smallest_to_top(stack_a);
	}
}
