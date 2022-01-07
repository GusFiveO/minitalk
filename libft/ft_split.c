/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:39:01 by alorain           #+#    #+#             */
/*   Updated: 2021/11/26 15:51:59 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**malloc_split(const char *s1, char c)
{
	size_t	i;
	size_t	compt;
	char	**tab;

	i = 0;
	compt = 0;
	while (s1[i])
	{
		while (s1[i] == c && s1[i])
			i++;
		if (s1[i] != '\0')
		{
			compt++;
			while (s1[i] != c && s1[i])
				i++;
		}
	}
	tab = malloc(sizeof(char *) * (compt + 1));
	if (!tab)
		return (NULL);
	return (tab);
}

static char	*cpyword(const char *s, char c)
{
	size_t	i;
	size_t	len;
	char	*str;

	len = 0;
	i = 0;
	while (s[len] != c && s[len])
		len++;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_free(char **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
}

static void	*fill_tab(char **tab, const char *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[word] = cpyword(s + i, c);
			if (!tab[word])
			{
				ft_free(tab, word);
				return (NULL);
			}
			word++;
			while (s[i] != c && s[i])
				i++;
			i--;
		}
		i++;
	}
	tab[word] = NULL;
	return (tab);
}

char	**ft_split(const char *s1, char c)
{
	char	**tab;

	if (!s1)
		return (NULL);
	tab = malloc_split(s1, c);
	if (!tab)
		return (NULL);
	if (!fill_tab(tab, s1, c))
		return (NULL);
	return (tab);
}
