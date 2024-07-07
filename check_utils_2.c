#include "push_swap.h"

void	print_error(void)
{
	ft_printf("Error\n");
}

int	find_symbol(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			count += 1;
		}
		i++;
	}
	return (count);
}
