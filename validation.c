#include "push_swap.h"

// int check_duplicates(char **splitted_numbers)
// {
// }

int	check_overflow(char *splitted_numbers)
{
	int		i;
	int 	sign;
	long	nbr;
	
	nbr = 0;
	sign = 1;
	i = 0;
	if (splitted_numbers[i] == '-' || splitted_numbers[i] == '+')
	{
		if (splitted_numbers[i] == '-')
		{
			sign = -1;
			i++;
		}
	}
	while (ft_isdigit(splitted_numbers[i]))
	{
		if ((nbr * 10 + (splitted_numbers[i] - '0')) > INT_MAX || )
			return (0);
		i++;
	}
}
// if ((nbr = sign * nbr) > INT_MAX || (nbr = sign * nbr) < INT_MIN)
// 	return (0);

int valid_format(char **splitted_numbers)
{
	int	i;
	int	j;

	i = 0;
	while (splitted_numbers[i])
	{
		j = 0;
		if (splitted_numbers[i][j] == '\0')
			return (0);
		if (splitted_numbers[i][j] == '+' || splitted_numbers[i][j] == '-')
		{
			if (!splitted_numbers[i][j + 1])
				return (0);
			j++;
		}
		while (splitted_numbers[i][j])
		{
			if (!ft_isdigit(splitted_numbers[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_numbers(char **splitted_numbers)
{
	int i;

	if (!valid_format(splitted_numbers))
		return (0);
	i = 0;
	while (splitted_numbers[i])
	{
		if (!check_overflow(splitted_numbers[i]))
			return (0);
		i++;
	}
	// if (!check_duplicates(splitted_numbers))
	// 	return (0);
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
