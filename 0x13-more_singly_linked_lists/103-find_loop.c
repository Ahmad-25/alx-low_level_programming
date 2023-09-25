#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to search for
 *
 * Return: address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *a = head;
	listint_t *b = head;

	if (!head)
		return (NULL);

	while (a && b && b->n)
	{
		b = b->n->n;
		a = a->n;
		if (b == a)
		{
			a = head;
			while (a != b)
			{
				a = a->n;
				b = b->n;
			}
			return (b);
		}
	}

	return (NULL);
}
