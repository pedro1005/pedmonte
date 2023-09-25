/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:19:58 by pedmonte          #+#    #+#             */
/*   Updated: 2023/09/19 16:20:03 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libft/libft.h"

void	send_character(int pid, char c)
{
	int	bit_index;

	bit_index = 0;
	while (bit_index < 8)
	{
		if ((c >> bit_index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
		bit_index++;
	}
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("Message received\n");
		exit(0);
	}
	ft_printf("Message not received\n");
	exit(1);
}

void	check_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i++]))
		{
			ft_printf("PID invalid!\n");
			exit(1);
		}
	}
}

void	set_signals(struct sigaction *signal)
{
	ft_bzero(signal, sizeof(*signal));
	signal->sa_handler = sig_handler;
}

int	main(int argc, char *argv[])
{
	int					server_pid;
	char				*message;
	struct sigaction	signal;

	if (argc != 3)
	{
		ft_printf("Invalid arguments\n");
		exit(1);
	}
	check_pid(argv[1]);
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	set_signals(&signal);
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	sigaction(SIGALRM, &signal, NULL);
	while (*message)
		send_character(server_pid, *message++);
	send_character(server_pid, '\0');
	alarm(3);
	pause();
	return (0);
}
