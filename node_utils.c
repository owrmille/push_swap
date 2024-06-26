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