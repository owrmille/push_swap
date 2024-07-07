#include "push_swap.h"

char	**parse_input(char *input)
{
	char	**strings;

	if (input == NULL || *input == '\0')
	{
		print_error();
		return (NULL);
	}
	if (!(find_symbol(input, ' ')))
	{
		strings = malloc(sizeof(char *) * 2);
		if (strings == NULL)
			return (NULL);
		strings[0] = input;
		strings[1] = NULL;
	}
	else
	{
		strings = ft_split(input, ' ');
	}
	return (strings);
}

int	convert_and_append(char **strings, t_node **stack_a)
{
	int		i;
	long	number;

	i = 0;
	while (strings[i] != NULL)
	{
		number = ft_atol_for_nums(strings[i]);
		if (number > INT_MAX || number < INT_MIN
			|| !(check_doubles(*stack_a, (int)number)))
		{
			free_split(strings);
			print_error();
			return (0);
		}
		append_node(stack_a, (int)number);
		i++;
	}
	return (i);
}

int	check_str(char **argv, t_node **stack_a)
{
	char	**strings;
	int		result;

	strings = parse_input(argv[1]);
	if (strings == NULL)
		return (0);
	result = convert_and_append(strings, stack_a);
	free_split(strings);
	return (result);
}
