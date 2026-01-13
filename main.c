/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:59:27 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/11 21:57:53 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// O PRIMEIRO ARGUMENTO DEVE ESTAR NO TOPO
// INSTRUÇÕES SEPARADAS POR '/n'

int	main(int argc, char **argv)
{
	int	*numbers;
	int	i;
	int	size;

	size = 0;
	numbers = parce_input(argc, argv, &size);
	if (!numbers)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (1);
	}
	i = 0;
	while (i < size)
	{
		ft_printf("%d\n", numbers[i]);
		i++;
	}
	free(numbers);
	return (0);
}
