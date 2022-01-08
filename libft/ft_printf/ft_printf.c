/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:57:14 by alorain           #+#    #+#             */
/*   Updated: 2021/12/11 13:25:37 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		vl;
	size_t		i;
	size_t		printed_char;
	t_printf	flag;

	printed_char = 0;
	i = 0;
	va_start(vl, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			i += parse_flags(str + i, &flag);
			print_arg(&flag, vl);
		}
		if (!str[i])
			break ;
		if (str[i] != '%')
			write_buff((char *)&str[i++], 1);
	}
	printed_char = manage_buff(NULL, 0);
	va_end(vl);
	return (printed_char);
}
