#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	size;
	t_node	*stack_a = NULL;
	t_node	*stack_b = NULL;

	// stack_a = (t_node *)malloc(sizeof(t_node));
	if (!(size = check_nums(argc, argv, &stack_a)))
	{
		free_stack(stack_a);
		exit(0);
	}
	else
	{
		// --swap-- :
		// ft_printf("HEAD: %d\n", stack_a->nbr);
		// print_stack(stack_a);
		// sa(&stack_a);
		// ft_printf("After swap:\n");
		// ft_printf("HEAD: %d\n", stack_a->nbr);
		// print_stack(stack_a);

		// --rotate-- :
		// ft_printf("HEAD: %d\n", stack_a->nbr);
		// print_stack(stack_a);
		// ra(&stack_a);
		// ft_printf("After rotate:\n");
		// ft_printf("HEAD: %d\n", stack_a->nbr);
		// print_stack(stack_a);

		// --reverse_rotate-- :
		// ft_printf("HEAD: %d\n", stack_a->nbr);
		// print_stack(stack_a);
		// rra(&stack_a);
		// ft_printf("After reverse rotate:\n");
		// ft_printf("HEAD: %d\n", stack_a->nbr);
		// print_stack(stack_a);

		// --push-- :
		// ft_printf("HEAD: %d\n", stack_a->nbr);
		// print_stack(stack_a);
		// print_stack(stack_b);

		// pb(&stack_a, &stack_b);
		// print_stack(stack_a);
		// print_stack(stack_b);

		// pb(&stack_a, &stack_b);
		// print_stack(stack_a);
		// print_stack(stack_b);

		// pb(&stack_a, &stack_b);
		// print_stack(stack_a);
		// print_stack(stack_b);

		// pb(&stack_a, &stack_b);
		// print_stack(stack_a);
		// print_stack(stack_b);

		print_stack(stack_a);
		sort_three_nodes(&stack_a);
		print_stack(stack_a);

		free_stack(stack_a);
		free_stack(stack_b);
	}
	return (0);
}