/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:49:12 by alorain           #+#    #+#             */
/*   Updated: 2022/01/12 16:02:47 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	_power(int n, int power)
{
	if (power != 0)
		return (n * _power(n, power - 1));
	else
		return (1);
}

int	ft_strlcat2(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = 0;
	return (i + j);
}

char	ft_bitoa(char *str)
{
	int		i;
	int		count;
	int		asc;

	i = 0;
	asc = 0;
	count = 7;
	while (i < 8)
	{
		if (str[i] == '1')
			asc += _power(2, count);
		count--;
		i++;
	}
	return (asc);
}

void	quit(char *str)
{
	free(str);
	exit(1);
}

void	reset_struct(t_talk *talk)
{
	talk->str = NULL;
	talk->idx = 0;
	talk->time_offset = 0;
}
