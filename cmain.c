#include "push_swap.h"

int	main(int argc, char **argv)
{
	stack_t	*a;
	stack_t	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
		valid_numbers(argv);

}

