#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*first_node;
	t_node	*second_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;

	first_node = *stack;
	second_node = (*stack)->next;

	first_node->next = second_node->next;
	first_node->prev = second_node;
	second_node->next = first_node;
	second_node->prev = NULL;
	if (first_node->next != NULL)
	{
		first_node->next->prev = first_node;
	}
	(*stack) = second_node;
}

void	sa(t_node **stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_node **stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}
