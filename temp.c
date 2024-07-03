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

void	print_associates(t_node *stack_b)
{
	t_node *cur;

	cur = stack_b;
	while (cur)
	{
		// if (stack_b->associate == NULL)
		// 	ft_printf("Element: %d, Associate: NULL");
		// else
		ft_printf("\nNumber: %d, ", cur->nbr);
		ft_printf("Associate: %d\n", cur->associate);
		cur = cur->next;
	}
}

void	print_info(t_node *stack)
{
	t_node	*cur;

	cur = stack;
	while (cur)
	{
		ft_printf("\nNumber: %d, ", cur->nbr);
		ft_printf("Index: %d\n", cur->cur_idx);
		ft_printf("Top-half: %d\n", cur->top_half);
		ft_printf("Price: %d\n", cur->price_before_push);
		cur = cur->next;
	}
}
