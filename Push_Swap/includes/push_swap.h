#ifndef PUSH_SWAP__H
# define PUSH_SWAP__H

#include "../libft/libft.h"
#include <limits.h>

typedef struct s_stack_node {
	int					value;
	int					position;
	int					index;
	int					cost;
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
int				ft_check_order(t_stack_node *head);
int				ft_get_last_value(t_stack_node *head);
int				ft_get_max(t_stack_node *head);
int				ft_lstlen(t_stack_node *head);
int				ft_get_min_pos(t_stack_node *head);
int				ft_get_2ndmax(t_stack_node *head);
int				ft_get_min(t_stack_node *head);
int				ft_get_2ndmin(t_stack_node *head);
int				ft_get_max_pos(t_stack_node *head);
void			ft_set_index(t_stack_node **head,  int stack_size);
void			ft_leave_two(t_stack_node **head_a, t_stack_node **head_b);

#endif