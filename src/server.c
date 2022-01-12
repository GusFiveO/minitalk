/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:31:41 by alorain           #+#    #+#             */
/*   Updated: 2022/01/12 16:01:54 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_talk	g_talk;

int	acknowledgement(void)
{
	int	i;
	int	count;

	i = g_talk.idx;
	count = 0;
	if (i && i % 8 == 0)
	{
		while (i > g_talk.idx - 8 - 1)
		{
			if (g_talk.buffer[i] == '0')
				count++;
			i--;
		}
		if (count == 8)
		{
			if (kill(g_talk.c_pid, SIGUSR1) == -1)
				ft_printf("Cannot send SIGSUR1 to client\n");
			return (1);
		}
	}
	return (0);
}

void	concat(void)
{
	int		old_len;
	int		new_len;
	char	*new_str;
	int		idx_str;
	int		i;

	old_len = ft_strlen(g_talk.str) + 1;
	new_len = old_len + g_talk.idx / 8;
	new_str = malloc(sizeof(char) * (new_len + 1));
	if (!new_str)
		quit(g_talk.str);
	new_str[0] = '\0';
	idx_str = ft_strlcat2(new_str, g_talk.str);
	i = 0;
	while (i <= g_talk.idx)
	{
		if (i && i % 8 == 0)
			new_str[idx_str++] = ft_bitoa(&g_talk.buffer[i - 8]);
		i++;
	}
	new_str[idx_str] = '\0';
	free(g_talk.str);
	g_talk.str = new_str;
}

void	manage_buffer(void)
{
	if (!g_talk.str)
	{
		g_talk.str = malloc(sizeof(char));
		if (!g_talk.str)
			exit(1);
		g_talk.str[0] = '\0';
	}
	concat();
	g_talk.time_offset += 1;
}

void	sig_pid(int sig, siginfo_t *info, void *content)
{
	(void)content;
	g_talk.c_pid = info->si_pid;
	if (g_talk.idx < BUFFER_SIZE)
	{
		if (sig == SIGUSR1)
			g_talk.buffer[g_talk.idx] = '1';
		else if (sig == SIGUSR2)
			g_talk.buffer[g_talk.idx] = '0';
		g_talk.idx++;
		usleep(400 + g_talk.time_offset);
		g_talk.buffer[g_talk.idx + 1] = 0;
		if (kill(g_talk.c_pid, SIGUSR2) == -1)
			ft_printf("Cannot send SIGUSR2 to client\n");
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &sig_pid;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
		if (g_talk.idx >= BUFFER_SIZE)
			manage_buffer();
		if (acknowledgement())
		{
			manage_buffer();
			ft_printf("bytes received: %d\n", ft_printf("%s\n", g_talk.str));
			free(g_talk.str);
			reset_struct(&g_talk);
		}
		else if (g_talk.idx >= BUFFER_SIZE)
			g_talk.idx = 0;
	}
	return (0);
}
