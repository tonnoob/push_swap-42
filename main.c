/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:59:27 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/06 19:59:28 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// O PRIMEIRO ARGUMENTO DEVE ESTAR NO TOPO
// INSTRUÇÕES SEPARADAS POR '/n'

int	main(int argc, char **argv)
{
	int	*numbers;
	int	i;
	int size;

	numbers = parce_input(argc, argv);
	if (!numbers || !numbers[0])
	{
		ft_printf("Error\n");
		return (1);
	}
	else
	{
		i = 0;
		size = argc - 1;
		while (i < size)
		{
			ft_printf("%d", numbers[i]);
			write(1, "\n", 1);
			i++;
		}
		return (0);
	}
}
