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

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*create_node(int n)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = n;
	node->next = NULL;
	node->index = -1;
	return (node);
}

void	free_list(t_stack *stack)
{
	t_node	*current;
	t_node	*node_free;

	current = stack->top;
	while (current != NULL)
	{
		node_free = current;
		current = current->next;
		free(node_free);
	}
	stack->size = 0;
	stack->top = NULL;
	free(stack);
	stack = NULL;
}

void	connect_stack(t_stack *stack, int *numbers, int size)
{
	t_node	*new_node;
	t_node	*last;
	int		i;	

	i = 0;
	while (i < size)
	{
		new_node = create_node(numbers[i]);
		if (!new_node)
		{
			free_list(stack);
			return ;
		}
		if (!stack->top)
			stack->top = new_node;
		else
			last->next = new_node;
		last = new_node;
		stack->size++;
		i++;
	}
}
