#include "push_swap.h"

t_node	*find_last_node(t_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	append_node(t_node **stack, int number)
{
	t_node	*node;
	t_node	*cur_last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_node));
	if (node == NULL)
		return ;
	node->nbr = number;
	node->next = NULL;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		cur_last_node = find_last_node(*stack);
		cur_last_node->next = node;
		node->prev = cur_last_node;
	}
}

t_node	*find_smallest_node(t_node *stack)
{
	int			smallest;
	t_node		*smallest_node;

	if (NULL == stack)
		return (NULL);
	smallest = INT_MAX;
	while (stack)
	{
		if (stack->nbr < smallest)
		{
			smallest = stack->nbr;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_node	*find_cheapest_node(t_node *stack)
{
	while (stack)
	{
		if (stack->cheapest_price == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_node	*find_associate_node(t_node *node_b, t_node *stack_a)
{
	while (stack_a)
	{
		if (node_b->associate == stack_a->nbr)
			return (stack_a);
		stack_a = stack_a->next;
	}
	return (NULL);
}
