#include "push_swap.h"

void	sort(int size, t_node **stack_a, t_node **stack_b)
{
	(void)stack_b;
	if (is_stack_sorted(*stack_a))
		return ;
	if (size == 3)
		sort_three_nodes(stack_a);
}