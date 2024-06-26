#include "push_swap.h"

void	print_error()
{
	ft_printf("Error\n");
}

int check_doubles(t_node *stack, int number)
{
	if (stack == NULL)
		return (1);
	while (stack)
	{
		if (stack->nbr == number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_str(char **argv, t_node **stack_a)
{
	char	**strings;
	int	i;
	long	number;

	i = 0;
	if (*argv[1] == '\0')
	{
		print_error();
		return(0);
	}
	strings = ft_split(argv[1], ' ');
	while(strings[i] != NULL)
	{
		// ft_printf("Number: %s\n", strings[i]);
		number = ft_atol_for_nums(strings[i]);
		if (number > INT_MAX || number < INT_MIN || !(check_doubles(*stack_a, (int)number)))
		{
			print_error();
			return(0);
		}
		append_node(stack_a, (int)number);
		i++;
	}
	return (i);
}

int check_args(int argc, char **argv, t_node **stack_a)
{
	int	i;
	long	number;

	i = 1;
	while(i < argc)
	{
		number = ft_atol_for_nums(argv[i]);
		if (number > INT_MAX || number < INT_MIN || !(check_doubles(*stack_a, (int)number)))
		{
			print_error();
			return(0);
		}
		append_node(stack_a, (int)number);
		i++;
	}
	return (i - 1);
}

int	check_nums(int argc, char **argv, t_node **stack_a)
{
	if (argc <= 1)
	{
		print_error();
		return(0);
	}
	else if (argc == 2)
	{
		return (check_str(argv, stack_a));
	}
	else if(argc > 2)
	{
		return (check_args(argc, argv, stack_a));
	}
	return(0);
}