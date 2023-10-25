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

void	ft_order(t_stack_node **head_a, t_stack_node **head_b)
{
	int		len;
	int 	pos;
	int		max;

	while (!ft_check_order(*head_a))
	{
		while (*head_a)
		{
			len = ft_lstlen(*head_a);
			pos = ft_get_min_pos(*head_a);
			max = ft_get_max(*head_a);
			
			if (pos <= (len/2 + 0.5))
			{
				while (pos > 0)
				{
					if ((*head_a)->value == max || (*head_a)->value == ft_get_2ndmax(*head_a))
					{
						ft_pb(head_a, head_b);
						ft_rb(head_b);
						pos--;
						max = ft_get_max(*head_a);
					}
					else if ((*head_a)->value == ft_get_2ndmin(*head_a))
					{
						ft_pb(head_a, head_b);
						pos--;
						max = ft_get_max(*head_a);
					}
					ft_ra(head_a);
					pos = ft_get_min_pos(*head_a);
				}
			}
			else
			{
				while (pos < len)
				{
					if ((*head_a)->value == max || (*head_a)->value == ft_get_2ndmax(*head_a))
						{
							ft_pb(head_a, head_b);
							ft_rb(head_b);
						}
					else if ((*head_a)->value == ft_get_2ndmin(*head_a))
						{
							ft_pb(head_a, head_b);
						}
					ft_rra(head_a);
					pos++;
				}
			}
			ft_pb(head_a, head_b);
		}
		max = ft_get_max(*head_b);
		while ((*head_b)->value != max || (*head_b)->value != ft_get_2ndmax(*head_b)) // FIX THIS!!!
		{
			if(((*head_b)->value) < ((*head_b)->next->value))
				ft_sb(head_b);
			ft_pa(head_a, head_b);
		}
		while (*head_b)
		{
			if(((*head_b)->value) < ((*head_b)->next->value))
				ft_sb(head_b);
			ft_rrb(head_b);
			ft_pa(head_a, head_b);
			ft_ra(head_a);			
		}
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
	if (ft_check_order(head_a))
		printf("Lista Ordenada\n");
	else
		printf("Lista por ordenar\n");
	ft_free_stack(&head_a);
	ft_free_stack(&head_b);
	return (0);
}
