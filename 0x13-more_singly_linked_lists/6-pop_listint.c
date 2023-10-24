#include "lists.h"
#include <stdlib.h>
/**
 * pop_listint - function that deletes the head node of a listint_t linked list
 *
 * @head: double pointer in the linked lists
 *
 * Return: 0 if the linked list is empty
 */
int pop_listint(listint_t **head)
{	listint_t *temp;
	int num;

	if (!head || !*head)
		return (0);

	num = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (num);
}
