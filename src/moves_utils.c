/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:47:40 by osousa-d          #+#    #+#             */
/*   Updated: 2026/02/08 17:50:56 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap_s(t_stack *a, t_stack *b, char *op)
{
	if (!ft_strncmp(op, "sa", 2))
		swap(a);
	else if (!ft_strncmp(op, "sb", 2))
		swap(b);
	else if (!ft_strncmp(op, "ss", 2))
	{
		swap(a);
		swap(b);
	}
	ft_printf("%s\n", op);
}

void	rotate_r(t_stack *a, t_stack *b, char *op)
{
	if (!ft_strncmp(op, "ra", 2))
		rotate(a);
	else if (!ft_strncmp(op, "rb", 2))
		rotate(b);
	else if (!ft_strncmp(op, "rr", 2))
	{
		rotate(a);
		rotate(b);
	}
	ft_printf("%s\n", op);
}

void	rotate_reverse_r(t_stack *a, t_stack *b, char *op)
{
	if (!ft_strncmp(op, "rra", 3))
		rotate_reverse(a);
	else if (!ft_strncmp(op, "rrb", 3))
		rotate_reverse(b);
	else if (!ft_strncmp(op, "rrr", 3))
	{
		rotate_reverse(a);
		rotate_reverse(b);
	}
	ft_printf("%s\n", op);
}
