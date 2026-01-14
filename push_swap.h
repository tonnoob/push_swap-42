/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 20:02:04 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/11 21:59:29 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintf/ft_printf/ft_printf.h"
# include "libftprintf/libft/libft.h"
# include <limits.h>

typedef struct node_s 
{
	int				value;
	int				index;
	struct node_s	*next;
} node_t;

typedef struct stack_s
{
	node_t	*top;
	int		size;
} stack_t;

int		arrlen(char **array);
void	free_split(char **arr);
int		*convert_arr(char **arr, int size);
char	**get_input(int argc, char **argv, int *need_free);

int		check_duplicates(int *numbers, int size);
int		check_overflow(char *str_splitted);
int		valid_format(char *str_splitted);
int		valid_numbers(char **str_splitted);
int		*parce_input(int argc, char **argv, int *size);

void	swap(stack_t *stack);
void	sa(stack_t *stk_a);
void	sb(stack_t *stk_b);
void	push(stack_t *stk_dest, stack_t *stk_src);
void	pb(stack_t *b, stack_t *a);
void	pa(stack_t *a, stack_t *b);
void	rotate(stack_t *stack);
void	ra(stack_t *stack_a);
void	rb(stack_t *stack_b);
void	rotate_reverse(stack_t *stack);
void	rra(stack_t	*stack_a);
void	rrb(stack_t	*stack_b);

// sa / sb: trocam os dois primeiros nós
// pa / pb: movem o primeiro nó de uma stack para a outra
// ra / rb: movem o primeiro nó para o final
// rra / rrb: movem o último nó para o topo

#endif
