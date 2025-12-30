#include "push_swap.h"

int	check_duplicates(int *splitted_numbers)
{
	int	i;
	int j;

	i = 0;
	while (i < splitted_numbers[i] - 1)
	{
		j = i + 1;
		while (j < splitted_numbers[i])
		{
			if (splitted_numbers[i] == splitted_numbers[j])
				return (0);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_overflow(char *splitted_numbers)
{
	int		i;
	int 	sign;
	long	nbr;
	long	limit;
	
	nbr = 0;
	sign = 1;
	i = 0;
	if (splitted_numbers[i] == '-' || splitted_numbers[i] == '+')
	{
		if (splitted_numbers[i] == '-')
			sign = -1;
		i++;
	}
	limit = 2147483648;
	if (sign == 1)
		limit = INT_MAX;
	while (ft_isdigit(splitted_numbers[i]))
	{
		if (nbr > (limit - (splitted_numbers[i] - '0')) / 10)
			return (0);
		nbr = nbr * 10 + (splitted_numbers[i] - '0');
		i++;
	}
	return (1);
}

int valid_format(char *splitted_numbers)
{
	int	i;

	i = 0;
	if (splitted_numbers[i] == '\0')
		return (0);
	if (splitted_numbers[i] == '+' || splitted_numbers[i] == '-')
	{
		if (!splitted_numbers[i + 1])
			return (0);
		i++;
	}
	while (splitted_numbers[i])
	{
		if (!ft_isdigit(splitted_numbers[i]))
			return (0);
		i++;
	}
	return (1);
}

//Organizar depois
//valid_numbers(char **numbers)
// {
//     int values[];
//     loop:
//         - check formato
//         - check overflow
//         - values[i] = atoi
//     check duplicatas em values
// }

int	valid_numbers(char **splitted_numbers)
{
	int i;
	int *numbers;

	i = 0;
	while (splitted_numbers[i])
	{
		if (!valid_format(splitted_numbers[i]))
			return (0);
		if (!check_overflow(splitted_numbers[i]))
			return (0);
		numbers[i] = ft_atoi(splitted_numbers[i]);
		i++;
	}
	if (!check_duplicates(numbers))
		return (0);
	return (1);
}
char	**parce_input(int argc, char **argv)
{
	char	**numbers;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (NULL);
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else if (argc > 2)
		numbers = argv + 1;
	if (!valid_numbers(numbers))
		return (NULL);
	return (numbers);
}
