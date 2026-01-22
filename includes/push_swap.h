/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 20:02:04 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/19 11:13:05 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libftprintf/ft_printf/ft_printf.h"
# include "./libftprintf/libft/libft.h"
# include <limits.h>

typedef struct node_s
{
	int				value;
	int				index;
	struct node_s	*next;
}	t_node;

typedef struct stack_s
{
	t_node	*top;
	int		size;
}	t_stack;

int		arrlen(char **array);
void	free_split(char **arr);
int		*convert_arr(char **arr, int size);
char	**get_input(int argc, char **argv, int *need_free);
int		check_duplicates(int *numbers, int size);
int		check_overflow(char *str_splitted);
int		valid_format(char *str_splitted);
int		valid_numbers(char **str_splitted);
int		*parce_input(int argc, char **argv, int *size);
t_stack	*init_stack(void);
t_node	*create_node(int n);
void	free_list(t_stack *stack);
void	connect_stack(t_stack *stack, int *numbers, int size);
int		count_pos(t_stack *stack_a, t_node *node_min);
t_node	*search_min_node(t_stack *stack_a);
void	rotate_min_to_top(t_stack *stack_a, int pos);
void	sort_two(t_stack *stack_a);
void	sort_three(t_stack *stack_a);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	mini_sort(t_stack *stack_a, t_stack *stack_b);
void	swap(t_stack *stack);
void	push(t_stack *stk_dest, t_stack *stk_src, char *op);
void	rotate(t_stack *stack);
void	rotate_reverse(t_stack *stack);
void	swap_s(t_stack *a, t_stack *b, char *op);
void	rotate_r(t_stack *a, t_stack *b, char *op);
void	rotate_reverse_r(t_stack *a, t_stack *b, char *op);
int		*ord_numbers(int *numbers, int size);
void	add_index(t_stack *stack, int *index, int size);
int		stacklen(t_stack *stack);
int		count_bits(int size);
void	radix_sort(t_stack *a, t_stack *b);

void	dispatcher(t_stack *a, t_stack *b);
t_stack	*launcher(int argc, char **argv);

#endif
