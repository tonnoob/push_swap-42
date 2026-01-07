/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:36:38 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/07 09:36:40 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int arrlen(char **array)
{
    int i;

    i = 0;
    while (array[i])
        i++;
    return (i);
}
char **get_input(int argc, char **argv, int *need_free)
{
    char **arr;

    *need_free = 0;
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

int *convert_arr(char **arr, int size)
{
    int *numbers;
    int i;

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
