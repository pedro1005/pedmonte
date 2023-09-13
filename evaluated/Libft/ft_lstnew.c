/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:20:50 by pedmonte          #+#    #+#             */
/*   Updated: 2023/04/25 16:51:54 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(*res));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}
/*
int		main(void)
{
	char	str[] = "lorem ipsum dolor sit";

	t_list	*elem;

	elem = ft_lstnew((void *)str);
	printf("\n%p\n", elem->content);
}*/
