#include "../includes/push_swap.h"

int	ft_check_order(t_stack_node *head)
{
	int	result;

	result = 1;
	if (!head)
		return (0);
	while (head->next)
	{
		if ((head->value) > ((head->next)->value))
			result = 0;
		head = head->next;
	}
	return (result);
}

int	ft_get_last_value(t_stack_node *head)
{
	t_stack_node	*current;

	current = head;
	while (current->next)
		current = current->next;
	return (current->value);
}

int	ft_get_max(t_stack_node *head)
{
	t_stack_node	*current;
	int				max;

	if (!head)
		return (0);
	current = head;
	max = head->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		if (!current->next)
			return (max);
		current = current->next;
	}
	return (max);
}

int	ft_get_min(t_stack_node *head)
{
	t_stack_node	*current;
	int				min;

	if (!head)
		return (0);
	current = head;
	min = head->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		if (!current->next)
			return (min);
		current = current->next;
	}
	return (min);
}

int	ft_get_2ndmin(t_stack_node *head)
{
	t_stack_node	*current;
	int				min;
	int				scnd_min;

	if (!head)
		return (0);
	current = head;
	min = ft_get_min(head);
	scnd_min = head->value;
	while (current)
	{
		if ((current->value < scnd_min) && (current->value > min))
			scnd_min = current->value;
		if (!current->next)
			return (scnd_min);
		current = current->next;
	}
	return (scnd_min);
}

int	ft_get_2ndmax(t_stack_node *head)
{
	t_stack_node	*current;
	int				max;
	int				scnd_max;

	if (!head)
		return (0);
	current = head;
	max = ft_get_max(head);
	scnd_max = head->value;
	while (current)
	{
		if ((current->value > scnd_max) && (current->value < max))
			scnd_max = current->value;
		if (!current->next)
			return (scnd_max);
		current = current->next;
	}
	return (scnd_max);
}
int	ft_lstlen(t_stack_node *head)
{
	t_stack_node	*current;
	int				len;

	current = head;
	len = 0;
	while (current->next)
	{
		len++;
		current = current->next;
	}
	len++;
	return (len);
}

int	ft_get_min_pos(t_stack_node *head)
{
	t_stack_node	*current;
	int				min;
	int				pos;

	current = head;
	min = head->value;
	pos = head->position;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			pos = current->position;
		}
		if (!current->next)
			break ;
		current = current->next;
	}
	return (pos);
}

int	ft_get_max_pos(t_stack_node *head)
{
	t_stack_node	*current;
	int				max;
	int				pos;

	current = head;
	max = head->value;
	pos = head->position;
	while (current)
	{
		if (current->value > max)
		{
			max = current->value;
			pos = current->position;
		}
		if (!current->next)
			break ;
		current = current->next;
	}
	return (pos);
}

int		ft_choose_pos(int len, int pos_max, int pos_min)
{
	int	dist_min = pos_min;
	int dist_max = pos_max;
	
	if (pos_max == pos_min)
		return (pos_max);
	if (pos_min > (len - pos_min + 1))
		dist_min = len - pos_min + 1;
	if (pos_max > (len - pos_max + 1))
		dist_max = len - pos_max + 1;
	if (dist_min < dist_max)
		return (pos_min);
	return (pos_max);
}

void	ft_leave_two(t_stack_node **head_a, t_stack_node **head_b)
{
	int	size;

	size = ft_lstlen(*head_a);
	while (ft_lstlen(*head_a) > 2)
	{
		if ((*head_a)->index > (size / 2))
		{
			ft_pb(head_a, head_b);
			ft_rb(head_b);
		}
		else
			ft_pb(head_a, head_b);
	}
}

void	ft_set_cost(t_stack_node **head_a, t_stack_node **head_b)
{
	t_stack_node	*current_a;
	t_stack_node	*current_b;
	int				cost_a;
	int				cost_b;

	cost_a = INT_MAX;
	cost_b = INT_MAX;
	current_a = *head_a;
	current_b = *head_b;
	while (current_b)
	{
		current.
	}

}

t_stack_node	*ft_get_target(t_stack_node *head)
{
	t_stack_node	*target;
	t_stack_node	*current;

	target = head;
	current = head;
	while (current)
	{
		if (current->cost < target->cost)
			target = current;
		if (!current->next)
			return (target);
		current = current->next;
	}
	return (target);
}

void	ft_order(t_stack_node **head_a, t_stack_node **head_b)
{
	t_stack_node	*target;

	ft_leave_two(head_a, head_b);
	ft_set_cost(head_a, head_b);
	target = ft_get_target(&head_b);
	/*int		len;
	int 	pos_min;
	int		pos_max;
	int		pos;
	int		max;



	while (!ft_check_order(*head_a))
	{
		while (*head_a)
		{
			len = ft_lstlen(*head_a);
			pos_min = ft_get_min_pos(*head_a);
			pos_max = ft_get_max_pos(*head_a);
			max = ft_get_max(*head_a);
			pos = ft_choose_pos(len, pos_max, pos_min);
			
			if (pos <= (len/2 + 0.5))
			{
				while (pos > 0)
				{
					ft_ra(head_a);
					pos--;
				}
			}
			else
			{
				while (pos < len)
				{
					ft_rra(head_a);
					pos++;
				}
			}
			if ((*head_a)->value == max)
			{
				ft_pb(head_a, head_b);
				ft_rb(head_b);
			}
			else
				ft_pb(head_a, head_b);
		}
		max = ft_get_max(*head_b);
		while ((*head_b)->value != max)
		{
			ft_pa(head_a, head_b);
		}
		while (*head_b)
		{
			if((*head_b)->next)
			{
				if(((*head_b)->value) < ((*head_b)->next->value))
					ft_sb(head_b);
			}
			ft_rrb(head_b);
			ft_pa(head_a, head_b);
			ft_ra(head_a);			
		}
	}*/
}

void	ft_set_index(t_stack_node **head,  int stack_size)
{
	t_stack_node *ptr;
    t_stack_node *highest;
    int value;

    while (--stack_size > 0)
    {
        ptr = *head;
        value = INT_MIN;
        highest = NULL;

        while (ptr)
        {
            if (ptr->value == INT_MIN && ptr->index == 0)
                ptr->index = 1;

            if (ptr->value > value && ptr->index == 0)
            {
                value = ptr->value;
                highest = ptr;
            }

            ptr = ptr->next;
        }

        if (highest != NULL)
            highest->index = stack_size;
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
	ft_order(&head_a, &head_b);
	ft_set_index(&head_a, ft_lstlen(head_a));
	ft_order(&head_a, &head_b);
	//ft_print_stack(head_a);
	if (ft_check_order(head_a))
		printf("Lista Ordenada\n");
	else
		printf("Lista por ordenar\n");
	ft_free_stack(&head_a);
	ft_free_stack(&head_b);
	return (0);
}
