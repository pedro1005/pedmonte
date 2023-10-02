#include "../includes/push_swap.h"

void	ft_check_errors(int argc) // incomplete
{
	if (argc == 1)
	{
		ft_printf("\n");
		exit(0);
	}
}

void	ft_print_stack(t_stack_node *head)
{
	t_stack_node *current;

	current = head;
	while (current != NULL)
	{
		ft_printf("node pos: %d || value: %d || adr: %p || prev: %p || next: %p\n", current->position, current->value, current,  current->prev, current->next);
		current = current->next;
	}
}

void	ft_free_stack(t_stack_node *head)
{
	t_stack_node	*current;
	t_stack_node	*temp;

	current = head;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

void	ft_fill_stack_a(t_stack_node **head_a, char **str)
{
	t_stack_node	*current;
	t_stack_node	*new_node;
	int				pos;

	current = NULL;
	pos = 0;
	while (*++str)
	{
		new_node = malloc(sizeof(t_stack_node));
		if (new_node == NULL)
			exit(1);
		new_node->value = ft_atoi(*str);
		new_node->next = NULL;
		new_node->prev = NULL;
		new_node->position = pos++;
		if (*head_a == NULL)
			*head_a = new_node;
		else
		{
			current->next = new_node;
			new_node->next = NULL;
			new_node->prev = current;
		}
		current = new_node;
	}
}

void	ft_swap(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;
	int				temp_position;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = (*head)->next;
    temp_position = first->position;
    first->position = second->position;
    second->position = temp_position;
    first->prev = second;
    second->prev = NULL;
    first->next = second->next;
    second->next = first;
    *head = second;
}

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
    t_stack_node	*node_to_pop;
	t_stack_node	*temp;

	if (*head_b == NULL)
		return ;
	node_to_pop = ft_pop(head_b);
	temp = *head_a;
	*head_a = node_to_pop;
	(*head_a)->next = temp;
	temp->prev = *head_a;
	ft_update_pos(head_a);
	ft_update_pos(head_b);
	ft_printf("pa\n");
}

void	ft_pb(t_stack_node **head_a, t_stack_node **head_b)
{
    t_stack_node	*node_to_pop;
	t_stack_node	*temp;

	if (*head_a == NULL)
		return ;
	node_to_pop = ft_pop(head_a);
	temp = *head_b;
	*head_b = node_to_pop;
	(*head_b)->next = temp;
	temp->prev = *head_b;
	ft_update_pos(head_a);
	ft_update_pos(head_b);
	ft_printf("pb\n");
}

t_stack_node	*ft_pop(t_stack_node **head) //need to free node_to_pop
{
	t_stack_node *node_to_pop;

	if (*head == NULL)
		return (NULL);
	node_to_pop = *head;
	if (node_to_pop->next)
		*head = node_to_pop->next;
	(*head)->prev = NULL;
	node_to_pop->next = NULL;
	node_to_pop->prev = NULL;
	ft_update_pos(head);
	return (node_to_pop);
}

void	ft_update_pos(t_stack_node **head_a)
{
	t_stack_node	*current;
	int				pos;

	current = *head_a;
	pos = 0;
	while (current != NULL)
	{
		current->position = pos++;
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	static t_stack_node	*head_a;
	static t_stack_node	*head_b;

	head_a = NULL;
	head_b = NULL;
	ft_check_errors(argc); // incomplete!!
	ft_fill_stack_a(&head_a, argv);
	ft_fill_stack_a(&head_b, argv);
	ft_printf("stack a\n");
	ft_print_stack(head_a);
	ft_printf("stack b\n");
	ft_print_stack(head_b);
	ft_pa(&head_a, &head_b);
	ft_printf("stack a\n");
	ft_print_stack(head_a);
	ft_printf("stack b\n");
	ft_print_stack(head_b);
	ft_pa(&head_a, &head_b);
	//ft_pa(&head_a, &head_b);
	//ft_pa(&head_a, &head_b);
	ft_printf("stack a\n");
	ft_print_stack(head_a);
	ft_printf("stack b\n");
	ft_print_stack(head_b);
	ft_free_stack(head_a);
	ft_free_stack(head_b);
	return (0);
}
