#include "push_swap.h"

long	ft_atoi_for_nums(const char	*str)
{
	long	sign_val;
	long	number;

	sign_val = 1;
	number = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign_val = -1;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number *= 10;
		number += *str - 48;
		if ((sign_val == 1 && number > INT_MAX) || (sign_val == -1 && - number < INT_MIN))
			return (0);
		str++;
	}
	if (*str != '\0' && !(ft_isdigit(*str)))
		return (0);
	return (sign_val * number);
}
