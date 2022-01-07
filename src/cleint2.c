/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleint2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:40:29 by alorain           #+#    #+#             */
/*   Updated: 2022/01/07 17:54:14 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_sig(int pid, int sig)
{
	static int	tries;
	int				i;

	if(sig == SIGUSR1)
		if (kill(pid, SIGUSR1) == -1)
			return (0);
	if(sig == SIGUSR2)
		if (kill(pid, SIGUSR2) == -1)
			return (0);
	if (usleep(1000000) == 0)
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
		while (count)
		{
			if (str[idx]&(1<<count))
				if (send_sig(pid, SIGUSR1) == -1)
					exit(1);
			else
				if (send_sig(pid, SIGUSR2) == -1)
					exit(1);
			count--;
		}
		idx++;
	}
	count = 7;
	while (count)
	{
		send_sig(pid, SIGUSR2);
		count--;
	}
}