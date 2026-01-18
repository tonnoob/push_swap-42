#include "./includes/push_swap.h"

int	count_pos(stack_t *stack_a, node_t *node_min)
{
	node_t	*current;
	int		pos;

	current = stack_a->top;
	pos = 0;
	while (current != node_min)
	{
		current = current->next;
		pos++;
	}
	return (pos);
}

node_t	*search_min_node(stack_t *stack_a)
{
	node_t	*current;
	node_t	*node_min;
	
	current = stack_a->top;
	node_min = current;
	while (current != NULL)
	{
		if (current->value < node_min->value)
			node_min = current;
		current = current->next;
	}
	return (node_min);
}

void	rotate_min_to_top(stack_t *stack_a, int pos)
{
	int	i;

	if (pos <= stack_a->size / 2)
	{
		while (pos)
		{
			ra(stack_a);
			pos--;
		}
	}
	else
	{
		i = stack_a->size - pos;
		while (i)
		{
			rra(stack_a);
			i--;
		}
	}
}
