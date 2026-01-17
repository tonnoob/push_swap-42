/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:46:34 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/14 11:46:37 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

// rra / rrb: movem o último nó para o topo

void	rotate_reverse(stack_t *stack)
{
	node_t	*top;
	node_t	*current;
	node_t	*last;

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

void	rra(stack_t	*stack_a)
{
	rotate_reverse(stack_a);
	ft_printf("rra\n");
}

void	rrb(stack_t	*stack_b)
{
	rotate_reverse(stack_b);
	ft_printf("rrb\n");
}
