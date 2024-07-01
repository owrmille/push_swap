#include "push_swap.h"

void	free_stack(t_node *stack)
{
	if (stack)
	{
		while (stack->next)
		{
			stack = stack->next;
			if (stack->prev)
			{
				free(stack->prev);
				stack->prev = NULL;
			}
		}
		free(stack);
		stack = NULL;
	}
}

void	free_array(char	**array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
}
