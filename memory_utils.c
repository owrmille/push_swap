#include "push_swap.h"

void	free_stack(t_node *stack)
{
	while(stack->next)
	{
		stack = stack->next;
		if (stack->prev)
		{
			free(stack->prev);
			stack->prev = NULL;
		}
	}
	if (stack)
	{
		free(stack);
		stack = NULL;
	}
}