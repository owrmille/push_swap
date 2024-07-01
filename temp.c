#include "push_swap.h"

void	print_stack(t_node *head)
{
	t_node	*current;

	current = head;
	if (current == NULL)
	{
		ft_printf("Stack is empty.\n");
		return ;
	}
	while (current != NULL)
	{
		ft_printf("%d -> ", current->nbr);
		current = current->next;
	}
	ft_printf("NULL\n");
}

void	print_string_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
	{
		ft_printf("Array is NULL\n");
		return ;
	}
	while (array[i] != NULL)
	{
		ft_printf("%s\n", array[i]);
		i++;
	}
}
