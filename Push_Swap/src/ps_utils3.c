#include "../includes/push_swap.h"

t_stack_node	*ft_pop(t_stack_node **head)
{
	t_stack_node *node_to_pop = *head;

    if (*head == NULL)
        return NULL; // Nothing to pop

    if (node_to_pop->next) {
        *head = node_to_pop->next;
        (*head)->prev = NULL;
    } else {
        *head = NULL; // The stack is empty after popping
    }

    node_to_pop->next = NULL;
    node_to_pop->prev = NULL;
    ft_update_pos(head);

    return node_to_pop;
}

void	ft_update_pos(t_stack_node **head_a)
{
	t_stack_node	*current;
	int				pos;

	current = *head_a;
	pos = 0;
	while (current)
	{
		current->position = pos++;
		current = current->next;
	}
}

void	ft_ra(t_stack_node **head_a)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*last;

	if (!(*head_a) || !(*head_a)->next)
		return ;
	first = *head_a;
	last = *head_a;
	second = (*head_a)->next;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	*head_a = second;
	(*head_a)->prev = NULL;
	ft_update_pos(head_a);
	ft_printf("ra\n");
}

void	ft_rb(t_stack_node **head_b)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*last;

	if (!(*head_b) || !(*head_b)->next)
		return ;
	first = *head_b;
	last = *head_b;
	second = (*head_b)->next;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	*head_b = second;
	(*head_b)->prev = NULL;
	ft_update_pos(head_b);
	ft_printf("rb\n");
}

void	ft_rotate_up(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*last;

	if (!(*head) || !(*head)->next)
		return ;
	first = *head;
	last = *head;
	second = (*head)->next;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	*head = second;
	(*head)->prev = NULL;
	ft_update_pos(head);
}
