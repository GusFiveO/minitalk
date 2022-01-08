/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:24:57 by alorain           #+#    #+#             */
/*   Updated: 2021/12/11 13:03:16 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static size_t	get_flags(t_printf *flag, const char *str)
{
	size_t	i;
	char	*flags;

	flags = "0+-# ";
	i = 0;
	while (is_in(str[i], flags))
	{
		if (str[i] == '0')
			flag->zero = 1;
		else if (str[i] == '+')
			flag->plus = 1;
		else if (str[i] == '-')
			flag->minus = 1;
		else if (str[i] == '#')
			flag->diez = 1;
		else if (str[i] == ' ')
			flag->space = 1;
		i++;
	}
	return (i);
}

static size_t	get_count(t_printf *flag, const char *str)
{
	size_t	nb_digit;

	nb_digit = 0;
	while (ft_isdigit(str[nb_digit]))
		nb_digit++;
	flag->count = ft_atoi(str);
	return (nb_digit);
}

static size_t	get_dot(t_printf *flag, const char *str)
{
	size_t	nb_digit;

	nb_digit = 0;
	if (str[nb_digit] == '.')
	{
		nb_digit++;
		while (ft_isdigit(str[nb_digit]))
			nb_digit++;
		flag->dot = ft_atoi(str + 1);
	}
	return (nb_digit);
}

static void	init_flags(t_printf *flag)
{
	flag->minus = 0;
	flag->plus = 0;
	flag->zero = 0;
	flag->diez = 0;
	flag->dot = -1;
	flag->space = 0;
	flag->count = 0;
	flag->type = 0;
}

size_t	parse_flags(const char *str, t_printf *flag)
{
	size_t		i;

	i = 0;
	init_flags(flag);
	i += get_flags(flag, str);
	i += get_count(flag, str + i);
	i += get_dot(flag, str + i);
	flag->type = str[i++];
	return (i);
}
