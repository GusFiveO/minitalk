/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:49:12 by alorain           #+#    #+#             */
/*   Updated: 2022/01/07 15:49:50 by alorain          ###   ########.fr       */
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

char	ft_bitoa(char *str)
{
	int		i;
	int		count;
	int 	asc;

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