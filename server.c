/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes <yes@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:05:48 by frbranda          #+#    #+#             */
/*   Updated: 2025/02/06 19:52:50 by yes              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <signal.h>

void	write_message(char c, int pid)
{
	static char	*message = NULL;

	if (!message)
	{
		message = ft_calloc(1, sizeof(char));
		if (!message)
			exit (EXIT_FAILURE);
	}
	if (c == '\0')
	{
		ft_printf ("%s\n", message);
		free (message);
		message = NULL;
		kill(pid, SIGUSR1);
	}
	else
	{
		message = ft_strjoin_mini(message, c);
		if (!message)
			exit (EXIT_FAILURE);
	}
}

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static char		c = 0;
	static int		bite = 0;

	(void) info;
	(void) ucontext;
	if (sig == SIGUSR2)
		c = (c << 1) | 1;
	else
		c = (c << 1) | 0;
	bite++;
	if (bite == 8)
	{
		write_message(c, info->si_pid);
		bite = 0;
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID e = %d \n", getpid());
	while (1)
		pause();
	return (0);
}
