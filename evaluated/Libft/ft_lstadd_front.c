/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:31:57 by pedmonte          #+#    #+#             */
/*   Updated: 2023/04/25 17:45:01 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
int main()
{
    // create a new list with one element
    t_list *lst = ft_lstnew("first element");

    // add a new element to the front of the list
    ft_lstadd_front(&lst, ft_lstnew("new first element"));

    // print the contents of the list
    while (lst)
    {
        printf("%s\n", (char *)lst->content);
        lst = lst->next;
    }

    return 0;
}
*/
