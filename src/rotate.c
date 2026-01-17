/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:46:07 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/14 11:46:09 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	rotate(stack_t *stack)
{
	node_t	*a;
	node_t	*current;

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

void	ra(stack_t *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(stack_t *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}
