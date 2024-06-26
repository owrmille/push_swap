#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	size;
	t_node *stack_a;

	// stack_a = (t_node *)malloc(sizeof(t_node));
	if (!(size = check_nums(argc, argv, &stack_a)))
	{
		// ft_printf("There are only mubers, size: %d\n", size);
		exit(0);
	}
	// stack_a = (t_node *)malloc(sizeof(t_node));
	// allocate_memory(stack_a, argv, size);
	// if (without_doubles())
	print_stack(stack_a);
	return (0);
}