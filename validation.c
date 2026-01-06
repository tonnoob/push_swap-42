/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 20:51:05 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/06 20:51:07 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ALOCAR MEMORIA NO PARCE_INPUT 


int	check_duplicates(int *numbers)
{
	int	i;
	int j;

	i = 0;
	while (i < numbers[i] - 1)
	{
		j = i + 1;
		while (j < numbers[i])
		{
			if (numbers[i] == numbers[j])
				return (0);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_overflow(char *str_splitted)
{
	int		i;
	int 	sign;
	long	nbr;
	long	limit;
	
	nbr = 0;
	sign = 1;
	i = 0;
	if (str_splitted[i] == '-' || str_splitted[i] == '+')
	{
		if (str_splitted[i] == '-')
			sign = -1;
		i++;
	}
	limit = 2147483648;
	if (sign == 1)
		limit = INT_MAX;
	while (ft_isdigit(str_splitted[i]))
	{
		if (nbr > (limit - (str_splitted[i] - '0')) / 10)
			return (0);
		nbr = nbr * 10 + (str_splitted[i] - '0');
		i++;
	}
	return (1);
}

int	valid_format(char *str_splitted)
{
	int	i;

	i = 0;
	if (str_splitted[i] == '\0')
		return (0);
	if (str_splitted[i] == '+' || str_splitted[i] == '-')
	{
		if (!str_splitted[i + 1])
			return (0);
		i++;
	}
	while (str_splitted[i])
	{
		if (!ft_isdigit(str_splitted[i]))
			return (0);
		i++;
	}
	return (1);
}

int	valid_numbers(char **str_splitted)
{
	int i;
	int *numbers;

	i = 0;
	numbers = NULL;
	while (str_splitted[i])
	{
		if (!valid_format(str_splitted[i]))
			return (0);
		if (!check_overflow(str_splitted[i]))
			return (0);
		numbers[i] = ft_atoi(str_splitted[i]);
		i++;
	}
	if (!check_duplicates(numbers))
		return (0);
	return (1);
}
int	*parce_input(int argc, char **argv)
{
	char	**str;
	int		*numbers;
	int		size;	
	int		i;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (NULL);
	if (argc == 2)
		str = ft_split(argv[1], ' ');
	else if (argc > 2)
		str = argv + 1;
	if (!valid_numbers(str))
		return (NULL);
	i = 0;

	numbers = NULL;
	while (str[i])
	{
		numbers[i] = ft_atoi(str[i]);
		i++;
	}
	return (numbers);
}
