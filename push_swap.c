#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	size;
	t_node	*stack_a; // = NULL;
	t_node	*stack_b; // = NULL;

	stack_a = NULL;
	stack_b = NULL;
	// stack_a = (t_node *)malloc(sizeof(t_node));
	if (!(size = check_nums(argc, argv, &stack_a)))
	{
		free_stack(stack_a);
		exit(0);
	}
	else
	{
	// 	ft_printf("size: %d\n", size);
	// 	ft_printf("A before:\n");
	// 	print_stack(stack_a);
	// 	ft_printf("B before:\n");
	// 	print_stack(stack_b);
	// 	ft_printf("\n");
		// print_info(stack_a);
		// print_info(stack_b);

		sort(size, &stack_a, &stack_b);


		// ft_printf("A (end)):\n");
		// print_stack(stack_a);
		// ft_printf("B (end):\n");
		// print_stack(stack_b);
		// ft_printf("\n");

		

		free_stack(stack_a);
		free_stack(stack_b);
	}
	return (0);
}
