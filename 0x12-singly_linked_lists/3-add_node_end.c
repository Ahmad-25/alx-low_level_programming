#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a linked list
 * @head: double pointer to the list_t list
 * @str: string to put in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *w;
	list_t *x = *head;
	unsigned int len = 0;

	while (str[len])
		len++;

	w = malloc(sizeof(list_t));
	if (!w)
		return (NULL);

	w->str = strdup(str);
	w->len = len;
	w->next = NULL;

	if (*head == NULL)
	{
		*head = w;
		return (w);
	}

	while (x->next)
		x = x->next;

	x->next = w;

	return (w);
}
