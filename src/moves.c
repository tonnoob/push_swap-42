/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 07:43:58 by osousa-d          #+#    #+#             */
/*   Updated: 2026/02/08 17:51:00 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*a;
	t_node	*b;

	if (!stack || stack->size < 2)
		return ;
	a = stack->top;
	b = a->next;
	a->next = b->next;
	b->next = a;
	stack->top = b;
}

void	push(t_stack *stk_dest, t_stack *stk_src, char *op)
{
	t_node	*tmp;

	if (!stk_src || !stk_dest || stk_src->size == 0)
		return ;
	tmp = stk_src->top;
	stk_src->top = tmp->next;
	stk_src->size--;
	tmp->next = stk_dest->top;
	stk_dest->top = tmp;
	stk_dest->size++;
	ft_printf("%s\n", op);
}

void	rotate(t_stack *stack)
{
	t_node	*a;
	t_node	*current;

	if (!stack || stack->size < 2)
		return ;
	a = stack->top;
	stack->top = a->next;
	current = stack->top;
	while (current->next != NULL)
		current = current->next;
	current->next = a;
	a->next = NULL;
}

void	rotate_reverse(t_stack *stack)
{
	t_node	*top;
	t_node	*current;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	current = stack->top;
	top = stack->top;
	while (current->next->next != NULL)
		current = current->next;
	last = current->next;
	last->next = top;
	current->next = NULL;
	stack->top = last;
}
