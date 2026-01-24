/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 01:37:44 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/24 01:37:47 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	*ord_numbers(int *numbers, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (numbers[j] > numbers[j + 1])
			{
				tmp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (numbers);
}

void	add_index(t_stack *stack, int *index, int size)
{
	t_node	*current;
	int		i;

	current = stack->top;
	while (current != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (index[i] == current->value)
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}
