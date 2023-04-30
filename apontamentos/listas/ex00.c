/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:39:23 by pedmonte          #+#    #+#             */
/*   Updated: 2023/04/30 18:17:10 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *push(node *head, int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

void print_list(node *head) {
    if (head == NULL) {
        printf("empty\n");
        return;
    }

    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void delete_list(node **head) {
    node *current = *head;
    node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

node	*reverse_list(node **head)
{
	node	*current = *head;
	node	*prev = NULL;
	node	*next;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
	return (*head);
}

int main() {
    node *head = NULL;
    
    head = push(head, 4);
    head = push(head, 3);
    head = push(head, 2);
    head = push(head, 1);

    print_list(head);
    reverse_list(&head);
    print_list(head);
    delete_list(&head);
    print_list(head);

    return 0;
}
