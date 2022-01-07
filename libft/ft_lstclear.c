/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:28:18 by alorain           #+#    #+#             */
/*   Updated: 2021/11/26 16:56:15 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*nxt;

	temp = *lst;
	while (temp)
	{
		nxt = temp->next;
		(*del)(temp->content);
		free(temp);
		temp = nxt;
	}
	*lst = NULL;
}
