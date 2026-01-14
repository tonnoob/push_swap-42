/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 07:22:23 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/13 07:22:33 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(stack_t *stk_dest, stack_t *stk_src)
{
	node_t	*tmp;

	if (!stk_src || !stk_dest || !stk_src->top)
		return ;
	tmp = stk_src->top;
	stk_src->top = tmp->next;
	tmp->next = stk_dest->top;
	stk_dest->top = tmp;
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
