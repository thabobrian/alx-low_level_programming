#include "lists.h"
#include <stdlib.h>

/**
 * sum_listint - calculates the sum of all the data in a listint_t list
 *
 * @head: pointer
 * Return: 0 if the list is empty
 */

int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
