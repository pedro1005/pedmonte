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

void	ft_order(t_stack_node **head_a, t_stack_node **head_b)
{
	t_stack_node	*temp_a;
	//t_stack_node	*temp_b;

	temp_a = *head_a;
	//temp_b = *head_b;
	while (temp_a->next)
	{
		printf("%d\n", temp_a->value);
		ft_sa(&temp_a);
		ft_rrb(head_b);
		temp_a = *head_a;
	}
}

int	main(int argc, char **argv)
{
	static t_stack_node	*head_a;
	static t_stack_node	*head_b;
	//static t_stack_node *pivot;

	head_a = NULL;
	head_b = NULL;
	//pivot = NULL;
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
