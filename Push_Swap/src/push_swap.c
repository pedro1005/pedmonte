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

int	get_last_value(t_stack_node *head)
{
	t_stack_node	*current;

	current = head;
	while (current->next)
		current = current->next;
	return (current->value);
}

void	ft_order(t_stack_node **head_a, t_stack_node **head_b)
{
	/*int 	pivot;
	int		pivot2;

	while (!ft_check_order(*head_a))
	{
		pivot = (*head_a)->value;
		ft_pb(head_a, head_b);
		pivot2 = (*head_a)->value;
		ft_ra(head_a);
		while ((pivot2 != (*head_a)->value))
		{
			if (((*head_a)->value) > pivot)
				ft_pb(head_a, head_b);
			if (((*head_a)->value) < pivot)
				ft_ra(head_a);
		}
		while((*head_b))
		{
			if ((*head_b)->value < (*head_a)->value)
			{
				ft_pa(head_a, head_b);
				ft_ra(head_a);
			}
			else
			{
				ft_pb(head_a, head_b);
				ft_rra(head_a);
			}
		}
		ft_ra(head_a);
	}*/
	int 	pivot;
	int		pivot2;

	while (!ft_check_order(*head_a))
	{
		pivot = (*head_a)->value;
		ft_pb(head_a, head_b);
		pivot2 = (*head_a)->value;
		if ((*head_a)->value > get_last_value(*head_a))
			ft_ra(head_a);
		else
			ft_rra(head_a);
		while ((pivot2 != (*head_a)->value))
		{
			if (((*head_a)->value) > pivot)
				ft_pb(head_a, head_b);
			if (((*head_a)->value) < pivot)
			{
				if ((*head_a)->value > get_last_value(*head_a))
						ft_ra(head_a);
				else
					ft_rra(head_a);
			}
		}
		while((*head_b))
		{
			pivot = (*head_b)->value;
			ft_pa(head_a, head_b);
			pivot2 = (*head_b)->value;
			if ((*head_b)->value > get_last_value(*head_b))
				ft_rb(head_b);
			else
				ft_rrb(head_b);
			while ((pivot2 != (*head_b)->value))
			{
				if (((*head_b)->value) > pivot)
					ft_pa(head_a, head_b);
				if (((*head_b)->value) < pivot)
				{
					if ((*head_b)->value > get_last_value(*head_b))
						ft_rb(head_b);
					else
						ft_rrb(head_b);
				}
			}
		}
		if ((*head_a)->value > get_last_value(*head_a))
			ft_ra(head_a);
		else
			ft_rra(head_a);
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
