/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:58:04 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/18 01:08:00 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	init_stack(stack_t *stack)
{
	stack->top = NULL;
	stack->size = 0;
	return ;
}

node_t	*create_node(int n)
{
	node_t	*node;

	node = malloc(sizeof(node_t));
	if (!node)
		return (NULL);
	node->value = n;
	node->next = NULL;
	return (node);
}

stack_t	*create_stack(int *numbers)
{
	

}	

void	build_stack(node_t *node, stack_t *stack)
{
	


	
}
