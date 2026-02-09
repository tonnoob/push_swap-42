/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:36:38 by osousa-d          #+#    #+#             */
/*   Updated: 2026/02/08 17:51:07 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	arrlen(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**get_input(int argc, char **argv, int *need_free)
{
	char	**arr;

	*need_free = 0;
	arr = NULL;
	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		*need_free = 1;
	}
	else if (argc > 2)
	{
		arr = argv + 1;
		*need_free = 0;
	}
	return (arr);
}

int	*convert_arr(char **arr, int size)
{
	int	*numbers;
	int	i;

	numbers = malloc(size * sizeof(int));
	if (!numbers)
		return (NULL);
	i = 0;
	while (i < size)
	{
		numbers[i] = ft_atoi(arr[i]);
		i++;
	}
	return (numbers);
}
