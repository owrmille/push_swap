/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatopchu <iatopchu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 01:21:01 by iatopchu          #+#    #+#             */
/*   Updated: 2024/07/08 01:21:02 by iatopchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node *stack)
{
	if (stack)
	{
		while (stack->next)
		{
			stack = stack->next;
			if (stack->prev)
			{
				free(stack->prev);
				stack->prev = NULL;
			}
		}
		free(stack);
		stack = NULL;
	}
}

void	free_array(char	**array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
}

void	free_split(char **strings)
{
	int	i;

	i = 0;
	if (!strings)
		return ;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}
