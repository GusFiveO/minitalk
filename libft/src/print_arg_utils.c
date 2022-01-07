/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <augustinlorain@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:57:38 by augustinlor       #+#    #+#             */
/*   Updated: 2021/12/12 17:01:39 by augustinlor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	manage_0_dot(t_printf *flag)
{
	if (!flag->count)
		return ;
	if (flag->plus || flag->count)
		return ;
	else
		write_buff(" ", 1);
}

void	manage_diez(t_printf *flag, int nbr)
{
	if (nbr && flag->diez && flag->type == 'X')
		write_buff("0X", 2);
	if (nbr && flag->diez && flag->type == 'x')
		write_buff("0x", 2);
}

void	manage_prefix(t_printf *flag, int nbr)
{
	if (nbr < 0)
		write_buff("-", 1);
	if (flag->space && nbr >= 0 && !flag->plus)
		write_buff(" ", 1);
	if (flag->plus && nbr >= 0)
		write_buff("+", 1);
}

void	manage_percent(t_printf *flag)
{
	if (!flag->zero && !flag->minus)
		print_char(' ', flag->count - 1);
	if (flag->zero && !flag->minus)
		print_char('0', flag->count - 1);
	write_buff("%", 1);
	if (flag->minus)
		print_char(' ', flag->count - 1);
}
