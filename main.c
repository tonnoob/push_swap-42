#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	int j;

	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				ft_printf("%c", argv[i][j]);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
		return (0);
	}
	else
	{
		write(1, "\n", 1);
		return (1);
	}
}
