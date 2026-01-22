#include "./includes/push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*current;

	current = a->top;
	while (current != NULL && current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	dispatcher(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size <= 5)
		mini_sort(a, b);
	else
		radix_sort(a, b);
}
