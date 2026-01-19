/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:58:51 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/18 01:11:24 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

stack_t	*create_node(int *numbers)
{
	int	i;

	i = 0;
	n
}

int	main(int argc, char **argv)
{
	stack_t	*a;
	stack_t	*b;
	int		*numbers;
	int		size;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	size = 0;
	numbers = parce_input(argc, argv, &size);
	if (!numbers)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (1);
	}

	
}

