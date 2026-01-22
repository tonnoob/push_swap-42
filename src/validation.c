/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 20:51:05 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/18 01:03:05 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	check_duplicates(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_overflow(char *arr)
{
	int		i;
	int		sign;
	long	nbr;
	long	limit;

	nbr = 0;
	sign = 1;
	i = 0;
	if (arr[i] == '-' || arr[i] == '+')
	{
		if (arr[i] == '-')
			sign = -1;
		i++;
	}
	limit = 2147483648;
	if (sign == 1)
		limit = INT_MAX;
	while (ft_isdigit(arr[i]))
	{
		if (nbr > (limit - (arr[i] - '0')) / 10)
			return (0);
		nbr = nbr * 10 + (arr[i] - '0');
		i++;
	}
	return (1);
}

int	valid_format(char *arr)
{
	int	i;

	i = 0;
	if (arr[i] == '\0')
		return (0);
	if (arr[i] == '+' || arr[i] == '-')
	{
		if (!arr[i + 1])
			return (0);
		i++;
	}
	while (arr[i])
	{
		if (!ft_isdigit(arr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	valid_numbers(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (!valid_format(arr[i]))
			return (0);
		if (!check_overflow(arr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	*parce_input(int argc, char **argv, int	*size)
{
	char	**arr;
	int		*numbers;
	int		need_free;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (NULL);
	arr = get_input(argc, argv, &need_free);
	if (!valid_numbers(arr))
	{
		if (need_free)
			free_split(arr);
		return (NULL);
	}
	*size = arrlen(arr);
	numbers = convert_arr(arr, *size);
	if (need_free)
		free_split(arr);
	if (!numbers)
		return (NULL);
	if (!check_duplicates(numbers, *size))
	{
		free(numbers);
		return (NULL);
	}
	return (numbers);
}
