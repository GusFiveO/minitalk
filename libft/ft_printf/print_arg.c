/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <augustinlorain@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:31:56 by alorain           #+#    #+#             */
/*   Updated: 2021/12/12 16:59:27 by augustinlor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static void	manage_uinteger(t_printf *flag, unsigned int nbr)
{
	int	nb_digits;
	int	temp_dot;

	temp_dot = flag->dot;
	nb_digits = count_digit_base_un(nbr, 10);
	reg_dot(flag, nb_digits, nbr);
	if (!flag->zero && !flag->minus)
		print_char(' ', flag->count - flag->dot);
	else if (flag->zero && !flag->minus && temp_dot != -1)
		print_char(' ', flag->count - flag->dot);
	if (flag->plus && nbr > 0)
		write_buff("+", 1);
	if (flag->zero && !flag->minus && temp_dot == -1)
		print_char('0', flag->count - flag->dot);
	print_char('0', flag->dot - nb_digits);
	if (nbr == 0 && !temp_dot)
		manage_0_dot(flag);
	else
		ft_putnbr_base(nbr, "0123456789");
	if (flag->minus)
		print_char(' ', flag->count - flag->dot);
}

static void	manage_integer(t_printf *flag, int nbr)
{
	int	nb_digits;
	int	prefix;
	int	temp_dot;

	temp_dot = flag->dot;
	prefix = 0;
	if ((flag->plus && nbr >= 0) || (flag->count && nbr < 0)
		|| (flag->space && nbr >= 0))
		prefix ++;
	nb_digits = count_digit_base(nbr, 10);
	reg_dot(flag, nb_digits, nbr);
	if (!flag->zero && !flag->minus)
		print_char(' ', flag->count - flag->dot - prefix);
	else if (flag->zero && !flag->minus && temp_dot != -1)
		print_char(' ', flag->count - flag->dot - prefix);
	manage_prefix(flag, nbr);
	if (flag->zero && !flag->minus && temp_dot == -1)
		print_char('0', flag->count - flag->dot - prefix);
	print_char('0', flag->dot - nb_digits);
	if (nbr == 0 && !temp_dot)
		manage_0_dot(flag);
	else
		ft_putnbr(nbr);
	if (flag->minus)
		print_char(' ', flag->count - flag->dot - prefix);
}

static void	manage_hexa(t_printf *flag, unsigned int nbr, char *base)
{
	int	nb_digits;
	int	prefix;
	int	temp_dot;

	temp_dot = flag->dot;
	prefix = 0;
	if (nbr && flag->diez)
		prefix = 2;
	nb_digits = count_digit_base_un(nbr, 16);
	reg_dot(flag, nb_digits, nbr);
	if (!flag->zero && !flag->minus)
		print_char(' ', flag->count - flag->dot - prefix);
	else if (flag->zero && !flag->minus && temp_dot != -1)
		print_char(' ', flag->count - flag->dot - prefix);
	manage_diez(flag, nbr);
	if (flag->zero && !flag->minus && temp_dot == -1)
		print_char('0', flag->count - flag->dot - prefix);
	print_char('0', flag->dot - nb_digits);
	if (nbr == 0 && !temp_dot)
		manage_0_dot(flag);
	else
		ft_putnbr_base(nbr, base);
	if (flag->minus)
		print_char(' ', flag->count - flag->dot - prefix);
}

static void	manage_pointer(t_printf *flag, unsigned long p)
{
	int	nb_digits;

	nb_digits = count_digit_base_un(p, 16);
	reg_dot(flag, nb_digits, p);
	if (!flag->zero && !flag->minus)
	{
		print_char(' ', flag->count - flag->dot - 2);
		write_buff("0x", 2);
	}
	else if (flag->zero && !flag->minus)
	{
		write_buff("0x", 2);
		print_char('0', flag->count - flag->dot - 2);
	}
	else
		write_buff("0x", 2);
	print_char('0', flag->dot - nb_digits);
	ft_putnbr_base(p, "0123456789abcdef");
	if (flag->minus)
		print_char(' ', flag->count - flag->dot - 2);
}

void	print_arg(t_printf *flag, va_list vl)
{
	if (flag->type == 'c')
		manage_char(flag, (char)(va_arg(vl, int)));
	if (flag->type == 'i' || flag->type == 'd')
		manage_integer(flag, va_arg(vl, int));
	if (flag->type == 'x')
		manage_hexa(flag, va_arg(vl, unsigned int), "0123456789abcdef");
	if (flag->type == 'X')
		manage_hexa(flag, va_arg(vl, unsigned int), "0123456789ABCDEF");
	if (flag->type == 's')
		manage_string(flag, va_arg(vl, char *));
	if (flag->type == 'u')
		manage_uinteger(flag, va_arg(vl, unsigned int));
	if (flag->type == 'p')
		manage_pointer(flag, va_arg(vl, unsigned long));
	if (flag->type == '%')
		manage_percent(flag);
}
