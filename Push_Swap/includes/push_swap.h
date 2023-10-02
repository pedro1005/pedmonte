#ifndef PUSH_SWAP__H
# define PUSH_SWAP__H

#include "../libft/libft.h"

typedef struct s_stack_node {
	int			value;
	int			position;
	struct s_stack_node *next;
	struct s_stack_node *prev;
} t_stack_node;

#endif