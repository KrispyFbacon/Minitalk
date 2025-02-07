/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes <yes@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:57:58 by frbranda          #+#    #+#             */
/*   Updated: 2025/02/07 15:15:58 by yes              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <signal.h>

int ack_received = 0;

void	write_string_to_bit(pid_t pid, int c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep (1000);
		i--;
	}
}

void	string_to_bit(pid_t pid, char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		write_string_to_bit(pid, str[i]);
		i++;
	}
	write_string_to_bit(pid, '\0');
}

void	message_return(int sig, siginfo_t *info, void *ucontext)
{
	(void) info;
	(void) ucontext;
	(void) sig;
	ft_printf ("Server recieved message successfully! :D\n");
	exit (EXIT_SUCCESS);
}

void ack_handler(int sig)
{
	(void)sig;
	ack_received = 1;
}


int	main(int argc, char **argv)
{
	pid_t				pid;
	int					i;
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_handler = ack_handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);

	if (argc != 3)
	{
		ft_printf("Error: Insert pid and a message\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		write_string_to_bit(pid, argv[2][i]);
		while (!ack_received)
			pause();
		ack_received = 0;
		i++;
	}
	write_string_to_bit(pid, '\0'); // Send null terminator
	while (!ack_received)
		pause();
	return (0);
}
