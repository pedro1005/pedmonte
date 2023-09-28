#ifndef PUSH_SWAP__H
# define PUSH_SWAP__H

#include "../libft/libft.h"

typedef struct s_stack_node {
	int			value;
	struct s_stack_head *head;
	struct s_stack_node *next;
	struct s_stack_node *prev;
} t_stack_node;

typedef struct s_stack_head {
	int	value;
	t_stack_node *next;
} t_stack_head;

#endif