/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes <yes@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:44:16 by yes               #+#    #+#             */
/*   Updated: 2025/02/07 17:38:29 by yes              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <signal.h>
#include <limits.h>

#define WAIT_TIME_MS 100

static int	g_receiver = 0;

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	(void) info;
	(void) ucontext;
	g_receiver = 1;
	if (sig == SIGUSR1)
		ft_printf("Message successfully sent!\n");
	exit(EXIT_SUCCESS);
}

void	send_char(char c, pid_t server_pid)
{
	size_t	i = CHAR_BIT;
	size_t	n = 0;

	while (i-- > 0)
	{
		n = 0;
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		while (g_receiver == 0)
		{
			if (n == 30)
			{
				ft_printf("No response from server\n");
				exit(EXIT_FAILURE);
			}
			n++;
			usleep(WAIT_TIME_MS);
		}
		g_receiver = 0;
	}
}

void	send_length(char *str, pid_t server_pid)
{
	size_t	i = 32;
	size_t	n = 0;
	size_t	len = ft_strlen(str);

	while (i-- > 0)
	{
		n = 0;
		if ((len >> i) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		while (g_receiver == 0)
		{
			if (n == 5)
			{
				ft_printf("No response from server\n");
				exit(EXIT_FAILURE);
			}
			n++;
			usleep(WAIT_TIME_MS);
		}
		g_receiver = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	size_t				i;
	pid_t				server_pid;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (0);
	}
	server_pid = ft_atoi(argv[1]);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_length(argv[2], server_pid);
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_char(argv[2][i], server_pid);
		i++;
	}
	send_char('\0', server_pid);
	while (1)
		pause();
	return (0);
}
