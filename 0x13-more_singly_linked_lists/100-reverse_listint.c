#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 *
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *p = NULL;
	listint_t *m = NULL;

	while (*head)
	{
		m = (*head)->m;
		(*head)->m = p;
		p = *head;
		*head = m;
	}

	*head = p;

	return (*head);
}
