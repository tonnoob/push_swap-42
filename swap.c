#include "push_swap.h"

void	swap(stack_t *stack)
{
	node_t	*a;
	node_t	*b;

	if (!stack || stack->size < 2)	
		return ;
	a = stack->top;
	b = a->next;

	a->next = b->next;
	b->next = a;
	stack->top = b;
}
void	sa(stack_t *stk_a)
{
	swap(stk_a);
	ft_printf("sa\n");
}
void	sb(stack_t *stk_b)
{
	swap(stk_b);
	ft_printf("sb\n");
}
