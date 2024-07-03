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

		// --sort 3 nodes--:
		// print_stack(stack_a);
		// sort_three_nodes(&stack_a);
		// print_stack(stack_a);

		ft_printf("size: %d\n", size);
		ft_printf("A before:\n");
		print_stack(stack_a);
		ft_printf("B before:\n");
		print_stack(stack_b);
		ft_printf("\n");

		sort(size, &stack_a, &stack_b);
		// print_associates(stack_b);
		print_indices(stack_a);
		print_indices(stack_b);

		ft_printf("\nA after:\n");
		print_stack(stack_a);
		ft_printf("B after:\n");
		print_stack(stack_b);


		free_stack(stack_a);
		free_stack(stack_b);
	}
	return (0);
}
