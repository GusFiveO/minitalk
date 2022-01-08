/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:14:51 by alorain           #+#    #+#             */
/*   Updated: 2022/01/08 14:51:26 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static void	flush_buff(char *buffer, size_t *n)
{
	write(1, buffer, *n);
	buffer[0] = '\0';
	*n = 0;
}

static size_t	concat_buff(char *buffer, char *str, size_t n, size_t idx)
{
	size_t	i;
	size_t	j;

	i = idx;
	j = 0;
	while (j < n && (i + j) < PRINTF_BUFFER_SIZE + 1)
	{
		buffer[i + j] = str[j];
		j++;
	}
	buffer[i + j] = '\0';
	return (j);
}

static void	manage_buff2(char *buf, size_t *i, size_t n, char *str)
{
	size_t	new_n;
	size_t	b_ad;

	b_ad = concat_buff(buf, str, n, *i);
	new_n = n - b_ad;
	*i += b_ad;
	if (n + *i > PRINTF_BUFFER_SIZE)
	{
		flush_buff(buf, i);
		manage_buff(&str[b_ad], new_n);
	}
}

size_t	manage_buff(char *str, size_t n)
{
	static char		buffer[PRINTF_BUFFER_SIZE + 1];
	static size_t	idx = 0;
	static size_t	printed_char = 0;
	size_t			temp;

	if (!n && !str)
	{
		flush_buff(buffer, &idx);
		temp = printed_char;
		printed_char = 0;
		return (temp);
	}
	else
	{
		manage_buff2(buffer, &idx, n, str);
		printed_char += n;
		return (printed_char);
	}
}

void	write_buff(char *str, size_t n)
{
	manage_buff(str, n);
}
