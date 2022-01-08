/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:33:45 by alorain           #+#    #+#             */
/*   Updated: 2022/01/08 12:54:59 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	correct_use()
{	
	ft_printf("[ERROR] Correct usage: ./client [PID] [content].\n");
	exit(1);	
}

/* void	send_sig(int pid, unsigned char byte)
{
	static int	tries;
	int				i;

	i = 1<<7;
	while (i)
	{
		if (byte&i)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		if (usleep(1000000) == 0)
		{
			tries++;
			ft_printf("Si\n");
			if (tries == 3)
			{
				ft_printf("Signal not received\n");
				exit(1);
			}
			send_sig(pid, byte);
		}
		i >>= 1;
		tries = 0;
	}
}

void	manage_sig(char *s_pid, char *str)
{
	int	pid;
	int	i;

	i = 0;
	pid = ft_atoi(s_pid);
	while (str[i])
	{
		send_sig(pid, str[i]);
		i++;
	} 
	send_sig(pid, str[i]);
} */

void	send_sig(int pid, int sig)
{
	static int	tries;

	if(sig == SIGUSR1)
		if (kill(pid, SIGUSR1) == -1)
			exit(1);
	if(sig == SIGUSR2)
		if (kill(pid, SIGUSR2) == -1)
			exit(1);
	if (usleep(100000) == 0)
	{
		tries++;
		ft_printf("Si\n");
		if (tries == 3)
		{
			ft_printf("Signal not received\n");
			exit(1);
		}
		send_sig(pid, sig);
	}
	tries = 0;
}

void	manage_sig(char *s_pid, char *str)
{
	int	pid;
	int	idx;
	int	count;

	idx = 0;
	pid = ft_atoi(s_pid);
	while (str[idx])
	{
		count = 7;
		while (count >= 0)
		{
			if (str[idx] & (1<<count))
				send_sig(pid, SIGUSR1);
			else
				send_sig(pid, SIGUSR2);
			count--;
		}
		idx++;
	}
	count = 7;
	while (count >= 0)
	{
		send_sig(pid, SIGUSR2);
		count--;
	}
}

void	handle_sigusr(int sig)
{
	static int send_bytes;

	if (sig == SIGUSR1)
		ft_printf("Message received\n");
	if (sig == SIGUSR2)
		send_bytes++;
}

int main(int argc, char **argv)
{
	struct sigaction sa;

	(void)argv;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = &handle_sigusr;
	if (argc != 3)
		correct_use();
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	manage_sig(argv[1], argv[2]);
	return (0);
}