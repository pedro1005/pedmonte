/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:20:11 by pedmonte          #+#    #+#             */
/*   Updated: 2023/09/19 16:20:20 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void	confirm_msg(siginfo_t *info, char *received_message)
{
	int			client_pid;

	ft_printf("Client_pid(%d): %s\n", info->si_pid, received_message);
	client_pid = info->si_pid;
	kill(client_pid, SIGUSR1);
}

void	sig_handler(int signum, siginfo_t *info)
{
	static char	*received_message;
	static int	bit_index;
	static char	received_char;
	static char	*temp;

	if (!bit_index | (bit_index > 7))
		bit_index = 0;
	if (signum == SIGUSR1)
		received_char = received_char | (1 << bit_index);
	bit_index++;
	if (bit_index == 8)
	{
		received_message = ft_strjoin(temp, &received_char);
		if (temp)
			free(temp);
		if (received_char == '\0')
		{
			confirm_msg(info, received_message);
			free(received_message);
			received_message = NULL;
		}
		temp = ft_strdup(received_message);
		free(received_message);
		received_char = '\0';
	}
}

int	main(void)
{
	struct sigaction	signal;

	ft_bzero(&signal, sizeof(signal));
	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = (void (*))sig_handler;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
