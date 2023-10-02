#ifndef PUSH_SWAP__H
# define PUSH_SWAP__H

#include "../libft/libft.h"

typedef struct s_stack_node {
	int					value;
	int					position;
	struct s_stack_node *next;
	struct s_stack_node *prev;
} t_stack_node;

void			ft_print_stack(t_stack_node *head);
void			ft_free_stack(t_stack_node *head);
void			ft_fill_stack_a(t_stack_node **head_a, char **str);
void			ft_swap(t_stack_node **head);
void			ft_sa(t_stack_node **head_a);
void			ft_sb(t_stack_node **head_b);
void			ft_ss(t_stack_node **head_a, t_stack_node **head_b);
void			ft_pa(t_stack_node **head_a, t_stack_node **head_b);
t_stack_node 	*ft_pop(t_stack_node **head);
void			ft_update_pos(t_stack_node **head_a);
void			ft_pb(t_stack_node **head_a, t_stack_node **head_b);
void			ft_pa(t_stack_node **head_a, t_stack_node **head_b);

#endif