#ifndef PUSH_SWAP__H
# define PUSH_SWAP__H

#include "../libft/libft.h"

typedef struct s_stack_node {
	int					value;
	int					position;
	struct s_stack_node *next;
	struct s_stack_node *prev;
} t_stack_node;

void			ft_check_errors(int argc);
void			ft_print_stack(t_stack_node *head);
void			ft_free_stack(t_stack_node **head);
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
void			ft_ra(t_stack_node **head_a);
void			ft_rb(t_stack_node **head_b);
void			ft_rotate_up(t_stack_node **head);
void			ft_rr(t_stack_node **head_a, t_stack_node **head_b);
void			ft_rotate_down(t_stack_node **head);
void			ft_rra(t_stack_node **head_a);
void			ft_rrb(t_stack_node **head_b);
void			ft_rrr(t_stack_node **head_a, t_stack_node **head_b);

#endif