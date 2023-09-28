#include "../includes/push_swap.h"

void	check_errors(int argc, char *argv[])
{
	if (argc == 1)
	{
		ft_printf("\n");
		exit(0);
	}
	if (argc >= 2)
	{
		printf("%s", argv[1]);
		return ;
	}
	ft_printf("Error\n");
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_stack_head	head_a;
	t_stack_head	head_b;

	ft_bzero(&head_a, sizeof(t_stack_head));
	ft_bzero(&head_b, sizeof(t_stack_head));
	check_errors(argc, argv);

	return(0);
}