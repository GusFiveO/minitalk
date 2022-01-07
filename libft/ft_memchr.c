/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:41:34 by alorain           #+#    #+#             */
/*   Updated: 2021/11/26 20:25:07 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n - 1 && p[i] != (unsigned char)c)
	{
		i++;
	}
	if (i == (n - 1) && p[i] != (unsigned char)c)
		return (NULL);
	return (&p[i]);
}
