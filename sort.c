#include "push_swap.h"

void	sort(int size, t_node **stack_a, t_node **stack_b)
{
	if (is_stack_sorted(*stack_a))
		return ;
	if (size == 3)
		sort_three_nodes(stack_a);
	//if (size == 5) to consider !!!
	else
	{
		while (size > 3)
		{
			pb(stack_a, stack_b);
			size--;
		} // push everything except 3 elems from a to b
		sort_three_nodes(stack_a); // sort a
		init_nodes(stack_a, stack_b);
		// while (*stack_b)
		// {

		// }
		

	}
}
