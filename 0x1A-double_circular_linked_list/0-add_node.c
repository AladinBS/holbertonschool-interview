#include "list.h"
/**
 * add_node_end - add node
 * @list: list
 * @str: string
 * Return: Address of the first node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *first, *last;

	if (!list || !str)
		return (NULL);

	first = malloc(sizeof(List));
	if (!first)
		return (NULL);

	first->str = strdup(str);
	if (!first->str)
	{
		free(first);
		return (NULL);
	}

	if (*list == NULL)
	{
		first->next = first->prev = first;
		*list = first;
		return (first);
	}

	last = (*list)->prev;

	last->next = first;
	first->next = *list;
	first->prev = last;
	(*list)->prev = first;

	return (first);
}

/**
 * add_node_begin - Add node
 * @list: list
 * @str: string
 * Return: Address of the first node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *first, *last;

	if (!list || !str)
		return (NULL);

	first = malloc(sizeof(List));
	if (!first)
		return (NULL);

	first->str = strdup(str);
	if (!first->str)
	{
		free(first);
		return (NULL);
	}

	if (*list == NULL)
	{
		first->next = first->prev = first;
		*list = first;
		return (first);
	}

	last = (*list)->prev;

	first->next = (*list);
	first->prev = last;
	(*list)->prev = last->next = first;
	*list = first;
	return (first);
}
