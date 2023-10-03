#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	static t_stack_node	*head_a;
	//static t_stack_node	*head_b;

	head_a = NULL;
	//head_b = NULL;
	ft_check_errors(argc); // incomplete!!
	ft_fill_stack_a(&head_a, argv);
	//ft_fill_stack_a(&head_b, argv);
	ft_printf("stack a\n");
	ft_print_stack(head_a);
	ft_rotate_down(&head_a);
	ft_printf("rotate down\n");
	ft_printf("stack a\n");
	ft_print_stack(head_a);
	/*ft_pb(&head_a, &head_b);
	ft_pb(&head_a, &head_b);
	ft_printf("stack a\n");
	ft_print_stack(head_a);
	ft_printf("stack b\n");
	ft_print_stack(head_b);
	ft_rr(&head_a, &head_b);
	ft_printf("stack a\n");
	ft_print_stack(head_a);
	ft_printf("stack b\n");
	ft_print_stack(head_b);
	*/
	ft_free_stack(&head_a);
	//ft_free_stack(&head_b);
	return (0);
}
