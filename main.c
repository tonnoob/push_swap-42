#include "push_swap.h"

// O PRIMEIRO ARGUMENTO DEVE ESTAR NO TOPO
// INSTRUÇÕES SEPARADAS POR '/n'

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
