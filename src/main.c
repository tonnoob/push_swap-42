/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:58:51 by osousa-d          #+#    #+#             */
/*   Updated: 2026/02/08 17:50:41 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*launcher(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (1);
	}
	a = launcher(argc, argv);
	if (!a)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (1);
	}
	b = init_stack();
	dispatcher(a, b);
	free_list(a);
	free_list(b);
	return (0);
}

t_stack	*launcher(int argc, char **argv)
{
	t_stack		*a;
	int			*numbers;
	int			*index;
	int			size;

	size = 0;
	numbers = parce_input(argc, argv, &size);
	if (!numbers)
		return (NULL);
	a = init_stack();
	connect_stack(a, numbers, size);
	if (!a)
		return (NULL);
	index = ord_numbers(numbers, size);
	add_index(a, index, size);
	free(numbers);
	return (a);
}
