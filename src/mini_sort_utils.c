/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:29:28 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/20 12:29:35 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	count_pos(t_stack *stack_a, t_node *node_min)
{
	t_node	*current;
	int		pos;

	current = stack_a->top;
	pos = 0;
	while (current != node_min)
	{
		current = current->next;
		pos++;
	}
	return (pos);
}

t_node	*search_min_node(t_stack *stack_a)
{
	t_node	*current;
	t_node	*node_min;

	current = stack_a->top;
	node_min = current;
	while (current != NULL)
	{
		if (current->value < node_min->value)
			node_min = current;
		current = current->next;
	}
	return (node_min);
}

void	rotate_min_to_top(t_stack *stack_a, int pos)
{
	int	i;

	if (pos <= stack_a->size / 2)
	{
		while (pos)
		{
			rotate_r(stack_a, NULL, "ra");
			pos--;
		}
	}
	else
	{
		i = stack_a->size - pos;
		while (i)
		{
			rotate_reverse_r(stack_a, NULL, "rra");
			i--;
		}
	}
}
