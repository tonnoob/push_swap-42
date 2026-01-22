/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:30:09 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/20 12:30:10 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	stacklen(t_stack *stack);
int	count_bits(int size);

void	radix_sort(t_stack *a, t_stack *b)
{
	int		size;
	int		max_bits;
	int		bit;
	int 	i;

	size = stacklen(a);
	max_bits = count_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((a->top->index >> bit) & 1) == 0)
				push(b, a, "pb");
			else
				rotate_r(a, NULL, "ra");
			i++;
		}
		while (b->size != 0)
			push(a, b, "pa");
		bit++;
	}
}

int	stacklen(t_stack *stack)
{
	t_node	*current;
	int		i;

	i = 0;
	current = stack->top;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

int	count_bits(int size)
{
	int n;
	int	bits;

	if (size <= 1)
		return (0);
	n = size - 1;
	bits = 0;
	while (n > 0)
	{
		n >>= 1;
		bits++;
	}
	return (bits);
}
