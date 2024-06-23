#include "push_swap.h"

void	print_error()
{
	ft_printf("Error\n");
}

int	only_nums_in_str(char **argv)
{
	char	**strings;
	int	i;
	int	number;

	i = 0;
	strings = ft_split(argv[1], ' ');
	while(strings[i])
	{
		if (!(number = ft_atoi_for_nums(strings[i])))
		{
			print_error();
			// ft_printf("Number: %d", number);
			return(0);
		}
		// ft_printf("Number: %d\n", number);
		i++;
	}
	return (1);
}

int only_nums_in_args(int argc, char **argv)
{
	int	i;
	int	number;

	i = 1;
	while(i < argc)
	{
		if (!(number = ft_atoi_for_nums(argv[i])))
			{
				print_error();
				// ft_printf("Number: %d", number);
				return(0);
			}
		// ft_printf("Number: %d\n", number);
		i++;
	}
	return (1);
}

int	only_nums(int argc, char **argv)
{
	if (argc == 2)
	{
		return (only_nums_in_str(argv));
	}
	else if(argc > 2)
	{
		return (only_nums_in_args(argc, argv));
	}
	return(0);
}