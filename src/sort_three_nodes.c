/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatopchu <iatopchu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 01:21:43 by iatopchu          #+#    #+#             */
/*   Updated: 2024/07/08 01:21:44 by iatopchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_max_node(t_node *stack)
{
	t_node	*max_node;

	if (stack == NULL)
		return (NULL);
	max_node = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->nbr > max_node->nbr)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

void	sort_three_nodes(t_node **stack)
{
	t_node	*max_node;

	max_node = find_max_node(*stack);
	if (*stack == max_node)
		ra(stack);
	else if ((*stack)->next == max_node)
		rra(stack);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack);
}
