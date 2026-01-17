/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 05:43:26 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/17 05:43:28 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

//FAZER A FUNÇÃO MINI _SORT, DIMINUIR LINHAS DA SORT_FIVE

int	count_pos(stack_t *stack_a)
{
	while (current != node_min)
	{
		current = current->next;
		pos++;
	}
}

void	sort_two(stack_t *stack)
{

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
	node_t	*current;
	node_t	*node_min;
	int		pos;

	current = stack_a->top;
	node_min = current;
	while (current != NULL)
	{
		if (current->value < node_min->value)
			node_min = current;
		current = current->next;
	}
	pos = 0;
	current = stack_a->top;

	if (pos <= stack_a->size / 2)
		while (pos)
			ra(stack_a);
	else
		while (pos)
			rra(stack_a);
}
void	mini_sort(stack_t *stack)
{
	if (stack->size == 2)
		sort_two(stack);
	else if (stack->size == 3)
		sort_three(stack);
	else if (stack->size == 5)
		sort_five(stack);
	return ;
}
