/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:40:27 by alorain           #+#    #+#             */
/*   Updated: 2021/11/26 21:31:09 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isin(char const *s, const char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		offset;
	int		end_offset;
	char	*result;

	if (!s1)
		return (NULL);
	i = 0;
	while (ft_isin(set, s1[i]))
		i++;
	offset = i;
	i = ft_strlen(s1) - 1;
	while (ft_isin(set, s1[i]))
		i--;
	end_offset = i + 1;
	if ((end_offset - offset) < 0)
		offset = 0;
	result = malloc(sizeof(*result) * (end_offset - offset + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, (char *) &s1[offset], end_offset - offset + 1);
	return (result);
}
