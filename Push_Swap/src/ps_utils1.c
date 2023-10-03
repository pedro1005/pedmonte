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

	if (head == NULL)
		return ;
	current = head;
	while (current)
	{
		ft_printf("node pos: %d || value: %d || adr: %p || prev: %p || next: %p\n", current->position, current->value, current,  current->prev, current->next);
		if (current->next)
			current = current->next;
		else
			return ;
	}
}

void	ft_free_stack(t_stack_node **head)
{
	t_stack_node* current = *head;
    while (current) {
        t_stack_node* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
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