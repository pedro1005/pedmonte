/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:15:01 by pedmonte          #+#    #+#             */
/*   Updated: 2023/04/29 13:24:50 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (!lst)
		return ;
	while (*lst)
	{
		ptr = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = ptr;
	}
}
