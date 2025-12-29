#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintf/ft_printf/ft_printf.h"
# include "libftprintf/libft/libft.h"
# include <limits.h>

typedef struct node_s 
{
	int				value;
	struct node_s	*next;
} node_t;

typedef struct stack_s
{
	node_t	*top;
	int		size;
} stack_t;

// int		check_duplicates(char **splitted_numbers);
int		check_overflow(char *splitted_numbers);
int 	valid_format(char **splitted_numbers);
int		valid_numbers(char **splitted_numbers);
char	**parce_input(int argc, char **argv);



// sa / sb: trocam os dois primeiros nós
// pa / pb: movem o primeiro nó de uma stack para a outra
// ra / rb: movem o primeiro nó para o final
// rra / rrb: movem o último nó para o topo

#endif