/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes <yes@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:23:39 by yes               #+#    #+#             */
/*   Updated: 2025/02/07 17:39:02 by yes              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <signal.h>
#include <limits.h>

void	receive_length(int sig, int *bit, char **str, pid_t *client_pid, pid_t sender_pid)
{
	static int	len = 0;

	len = (len << 1) | (sig == SIGUSR1);
	if (++(*bit) == 32)
	{
		*bit = 0;
		*str = malloc((len + 1) * sizeof(char));
		if (!(*str))
		{
			len = 0;
			write(1, "Memory allocation failed\n", 25);
			return ;
		}
		*client_pid = sender_pid;
		len = 0;
	}
	kill(*client_pid, SIGUSR2);
}

void	receive_message(int sig, int *bit, char **str, pid_t *client_pid)
{
	static char	c = 0;
	static int	i = 0;

	c = (c << 1) | (sig == SIGUSR1);
	if (++(*bit) == 8)
	{
		(*bit) = 0;
		if (c == '\0')
		{
			(*str)[i] = '\0';
			ft_printf("%s\n", *str);
			kill(*client_pid, SIGUSR1);
			free(*str);
			*str = NULL;
			*client_pid = 0;
			i = 0;
			return ;
		}
		(*str)[i++] = c;
		c = 0;
	}
	kill(*client_pid, SIGUSR2);
}

void	handle_client(int sig, siginfo_t *info, void *ucontext)
{
	static int		bit = 0;
	static pid_t	client_pid = 0;
	static char		*str = NULL;

	(void)ucontext;
	if (client_pid == 0)
		client_pid = info->si_pid;
	if (str == NULL)
		receive_length(sig, &bit, &str, &client_pid, info->si_pid);
	else
		receive_message(sig, &bit, &str, &client_pid);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID = %d\n", getpid());
	sa.sa_sigaction = handle_client;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
