#include "lists.h"
#include <stdlib.h>

/**
 * find_listint_loop - function that finds the loop in a linked list
 * @head: pointer
 *
 * Return: NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *var2 = head;
	listint_t *var1 = head;

	if (!head)
		return (NULL);

	while (var1 && var2 && var2->next)

	{
		var2 = var2->next->next;
		var1 = var1->next;
		if (var2 == var1)
		{
			var1 = head;
			while (var1 != var2)
			{
				var1 = var1->next;
				var2 = var2->next;
			}
			return (var2);
		}
	}
	return (NULL);
}

