/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:07:24 by alorain           #+#    #+#             */
/*   Updated: 2021/12/11 12:58:56 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	reg_dot(t_printf *flag, int nb_digits, long nbr)
{
	if (!nbr && !flag->dot)
		nb_digits = 0;
	if (flag->dot < nb_digits)
		flag->dot = nb_digits;
}

int	reg_len(t_printf *flag, char *str)
{
	int	str_len;

	str_len = ft_strlen(str);
	if (flag->dot < str_len && flag->dot != -1)
		return (flag->dot);
	return (str_len);
}

size_t	count_digit_base(int n, int base_len)
{
	int		len;
	long	nb;

	len = 0;
	nb = n;
	if (nb <= 0)
		nb *= -1;
	if (nb == 0)
		len = 1;
	while (nb != 0)
	{
		len++;
		nb = nb / base_len;
	}
	return (len);
}

size_t	count_digit_base_un(unsigned long n, size_t base_len)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / base_len;
	}
	return (len);
}
