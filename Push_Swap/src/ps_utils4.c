#include "../includes/push_swap.h"

void	ft_rr(t_stack_node **head_a, t_stack_node **head_b)
{
	ft_rotate_up(head_a);
	ft_rotate_up(head_b);
	if ((*head_a)->next || (*head_b)->next)
		ft_printf("rr\n");
}

void	ft_rotate_down(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!(*head) || !(*head)->next)
		return ;
	first = *head;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = first;
	(last->prev)->next = NULL;
	last->prev = NULL;
	first->prev = last;
	(*head) = last;
	ft_update_pos(head);
}

void	ft_rra(t_stack_node **head_a)
{
	ft_rotate_down(head_a);
	if ((*head_a)->next)
		ft_printf("rra\n");
}

void	ft_rrb(t_stack_node **head_b)
{
	ft_rotate_down(head_b);
	if ((*head_b)->next)
		ft_printf("rrb\n");
}

void	ft_rrr(t_stack_node **head_a, t_stack_node **head_b)
{
	ft_rotate_down(head_a);
	ft_rotate_down(head_b);
	if ((*head_a)->next || (*head_b)->next)
		ft_printf("rrr\n");
}