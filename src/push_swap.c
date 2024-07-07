/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatopchu <iatopchu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 01:21:12 by iatopchu          #+#    #+#             */
/*   Updated: 2024/07/08 01:21:13 by iatopchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		size;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	size = check_nums(argc, argv, &stack_a);
	if (!size || is_stack_sorted(stack_a))
		free_stack(stack_a);
	else
	{
		sort(size, &stack_a, &stack_b);
		free_stack(stack_a);
		free_stack(stack_b);
	}
	return (0);
}
