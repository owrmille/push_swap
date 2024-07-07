/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatopchu <iatopchu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 01:20:43 by iatopchu          #+#    #+#             */
/*   Updated: 2024/07/08 01:20:44 by iatopchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(t_node *stack, int number)
{
	while (stack)
	{
		if (stack->nbr == number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_args(int argc, char **argv, t_node **stack_a)
{
	int		i;
	long	number;

	i = 1;
	while (i < argc)
	{
		number = ft_atol_for_nums(argv[i]);
		if (number > INT_MAX || number < INT_MIN
			|| !(check_doubles(*stack_a, (int)number)))
		{
			print_error();
			return (0);
		}
		append_node(stack_a, (int)number);
		i++;
	}
	return (i - 1);
}

int	check_nums(int argc, char **argv, t_node **stack_a)
{
	if (argc <= 1 || (argc == 2 && !argv[1][0]))
	{
		return (0);
	}
	else if (argc == 2)
	{
		return (check_str(argv, stack_a));
	}
	else if (argc > 2)
	{
		return (check_args(argc, argv, stack_a));
	}
	return (0);
}
