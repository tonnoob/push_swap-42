/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 05:43:26 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/18 00:40:23 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	sort_two(stack_t *stack_a)
{
	node_t	*a;
	node_t	*b;

	a = stack_a->top;
	b = a->next;
	if (b->value < a->value)
		sa(stack_a);
}

void	sort_three(stack_t *stack_a)
{
	node_t	*a;
	node_t	*b;
	node_t	*c;

	a = stack_a->top;
	b = a->next;
	c = b->next;
	if (a->value < c->value && c->value < b->value)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (c->value < b->value && b->value < a->value)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (b->value < a->value && a->value < c->value)
		sa(stack_a);
	else if (b->value < c->value && c->value < a->value)
		rra(stack_a);
	else if (c->value < a->value && a->value < b->value)
		ra(stack_a);
	else
		return ;
}

void	sort_five(stack_t *stack_a, stack_t *stack_b)
{
	node_t	*node_min;
	int		pos;
	int		init_size;

	init_size = stack_a->size;
	while (stack_a->size > 3)
	{
		node_min = search_min_node(stack_a);
		pos = count_pos(stack_a, node_min);
		rotate_min_to_top(stack_a, pos);
		pb(stack_b, stack_a);
	}
	sort_three(stack_a);
	while (stack_a->size != init_size)
		pa(stack_a, stack_b);
}

void	mini_sort(stack_t *stack_a, stack_t *stack_b)
{
	if (stack_a->size == 2)
		sort_two(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 5 || stack_a->size == 4)
		sort_five(stack_a, stack_b);
}
