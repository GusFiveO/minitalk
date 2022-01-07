/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:27:17 by alorain           #+#    #+#             */
/*   Updated: 2021/11/26 20:33:04 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t		i;
	int			j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return ((char *) str);
	while (str[i] && i < len)
	{
		if (str[i] == to_find[0])
		{
			while (str[i + j] && to_find[j] && str[i + j] == to_find[j]
				&& i + j < len)
			{
				j++;
			}
			if (to_find[j] == '\0')
				return ((char *) &str[i]);
		}
		i++;
	}
	return (NULL);
}
