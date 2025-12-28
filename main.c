#include "push_swap.h"
#include <stdio.h>

// O PRIMEIRO ARGUMENTO DEVE ESTAR NO TOPO
// INSTRUÇÕES SEPARADAS POR '/n'

int	valid_number(char **splitted_numbers)
{
	int	i;
	int	j;

	i = 0;
	while (splitted_numbers[i])
	{
		j = 0;
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
		if ((ft_atoi(splitted_numbers[i])) > INT_MAX || (ft_atoi(splitted_numbers[i]) < INT_MIN))
			return (0);
		i++;
	}
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
	if (!valid_number(numbers))
		return (NULL);
	return (numbers);
}


int	main(int argc, char **argv)
{
	char	**numbers;
	int		i;
	int		j;

	numbers = parce_input(argc, argv);
	if (!numbers || !numbers[0])
	{
		ft_printf("Error\n");
		return (1);
	}
	else
	{
		i = 0;

		while (numbers[i])
		{
			j = 0;
			while (numbers[i][j])
			{
				ft_printf("%c", numbers[i][j]);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
		return (0);
	}
}
