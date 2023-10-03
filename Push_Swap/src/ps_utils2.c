#include "../includes/push_swap.h"

void	ft_sa(t_stack_node **head_a)
{
	if (*head_a == NULL || (*head_a)->next == NULL)
		return ;
	ft_printf("sa\n");
	ft_swap(head_a);
}

void	ft_sb(t_stack_node **head_b)
{
	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	ft_printf("sb\n");
	ft_swap(head_b);
}

void	ft_ss(t_stack_node **head_a, t_stack_node **head_b)
{
	int	swap_status;

	swap_status = 0;
	if (*head_b != NULL && (*head_b)->next == NULL)
	{
		ft_swap(head_b);
		swap_status = 1;
	}
	if (*head_a != NULL || (*head_a)->next == NULL)
	{
		ft_swap(head_a);
		swap_status = 1;
	}
	if (swap_status == 1)
		ft_printf("ss\n");
	
}

void	ft_pa(t_stack_node **head_a, t_stack_node **head_b)
{
    if (*head_b == NULL)
        return; // Nothing to push

    t_stack_node *node_to_pop = ft_pop(head_b);

    if (*head_a == NULL) {
        *head_a = node_to_pop;
        (*head_a)->prev = NULL;
        (*head_a)->next = NULL;
    } else {
        t_stack_node *temp = *head_a;
        *head_a = node_to_pop;
        (*head_a)->next = temp;
        temp->prev = *head_a;
    }

    ft_update_pos(head_a);
    ft_printf("pa\n");
}

void	ft_pb(t_stack_node **head_a, t_stack_node **head_b)
{
    if (*head_a == NULL)
        return; // Nothing to push

    t_stack_node *node_to_pop = ft_pop(head_a);

    if (*head_b == NULL) {
        *head_b = node_to_pop;
        (*head_b)->prev = NULL;
        (*head_b)->next = NULL;
    } else {
        t_stack_node *temp = *head_b;
        *head_b = node_to_pop;
        (*head_b)->next = temp;
        temp->prev = *head_b;
    }

    ft_update_pos(head_b);
    ft_printf("pb\n");
}