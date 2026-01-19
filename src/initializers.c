/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:58:04 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/19 11:11:38 by otton-sousa      ###   ########.fr       */
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
	node->index = NULL;
	return (node);
}

void	free_list(stack_t *stack)
{
	node_t	*current;
	node_t	*node_free;
	current = stack->top;
	while (current != NULL)
	{
		node_free = current;
		current = current->next;
		free(node_free);
	}
	stack->size = 0;
	stack->top = NULL;
}

int	connect_stack(stack_t *a, int *numbers, int size)
{
	node_t	*new_node;
	node_t	*last;
	int		i;	

	i = 0;
	while (i < size)
	{
		new_node = create_node(numbers[i]);
		if (!new_node)
		{
			free_node(a);
			return (0);
		}
		if (!a->top)
			a->top = new_node;
		else
			last->next = new_node;
		last = new_node;
		a->size++;
		i++;
	}
	return (1);
}
