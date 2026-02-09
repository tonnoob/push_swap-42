/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 05:43:26 by osousa-d          #+#    #+#             */
/*   Updated: 2026/02/08 17:50:52 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_two(t_stack *stack_a)
{
	t_node	*a;
	t_node	*b;

	if (!stack_a)
		return ;
	a = stack_a->top;
	b = a->next;
	if (b->value < a->value)
		swap_s(stack_a, NULL, "sa");
	return ;
}

void	sort_three(t_stack *stack_a)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	a = stack_a->top;
	b = a->next;
	c = b->next;
	if (a->value < c->value && c->value < b->value)
	{
		rotate_reverse_r(stack_a, NULL, "rra");
		swap_s(stack_a, NULL, "sa");
	}
	else if (c->value < b->value && b->value < a->value)
	{
		swap_s(stack_a, NULL, "sa");
		rotate_reverse_r(stack_a, NULL, "rra");
	}
	else if (b->value < a->value && a->value < c->value)
		swap_s(stack_a, NULL, "sa");
	else if (b->value < c->value && c->value < a->value)
		rotate_r(stack_a, NULL, "ra");
	else if (c->value < a->value && a->value < b->value)
		rotate_reverse_r(stack_a, NULL, "rra");
	else
		return ;
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_min;
	int		pos;
	int		init_size;

	init_size = stack_a->size;
	while (stack_a->size > 3)
	{
		node_min = search_min_node(stack_a);
		pos = count_pos(stack_a, node_min);
		rotate_min_to_top(stack_a, pos);
		push(stack_b, stack_a, "pb");
	}
	sort_three(stack_a);
	while (stack_a->size != init_size)
		push(stack_a, stack_b, "pa");
}

void	mini_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sort_two(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 5 || stack_a->size == 4)
		sort_five(stack_a, stack_b);
	return ;
}
