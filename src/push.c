/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 07:22:23 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/17 20:39:39 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	push(stack_t *stk_dest, stack_t *stk_src)
{
	node_t	*tmp;

	if (!stk_src || !stk_src->size == 0)
		return ;
	tmp = stk_src->top;
	stk_src->top = tmp->next;
	stk_src->size--;
	tmp->next = stk_dest->top;
	stk_dest->top = tmp;
	stk_dest->size++;
}

void	pb(stack_t *b, stack_t *a)
{
	push(b, a);
	ft_printf("pb\n");
}

void	pa(stack_t *a, stack_t *b)
{
	push(a, b);
	ft_printf("pa\n");
}
