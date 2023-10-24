#include "lists.h"
#include <stdlib.h>

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list
 *
 * @head: pointer
 * @index: the parameter that specify the index of the node
 *
 * Return: NULL if the node does not exist
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int position = 0;

	while (head != NULL)
	{
		if (position == index)
		{
			return (head);
		}
		head = head->next;
		position++;
	}
	return (NULL);
}
