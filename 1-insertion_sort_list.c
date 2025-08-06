#include "sort.h"

/**
 * swap_nodes - Permet de swapper deux noeuds ensemble
 *
 * @list: Pointeur vers le noeud initiale.
 * @a: Premier noeud.
 * @b: Second noeud.
 */

void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
if (a == NULL || b == NULL || list == NULL || *list == NULL)
	{
	return;
	}
if (a->next != b)
	{
	return;
	}
a->next = b->next;
if (b->next)
	{
	b->next->prev = a;
	}
b->prev = a->prev;
if (a->prev)
	{
	a->prev->next = b;
	}
else
	{
	*list = b;
	}
b->next = a;
a->prev = b;
}

/**
 * insertion_sort_list - Verifie la data et classe les noeuds dans l'ordre
 *			croissant.
 * @list: Pointeur vers le noeud.
 */

void insertion_sort_list(listint_t **list)
{
listint_t *current, *back;
if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
	return;
	}
current = (*list)->next;

while (current)
	{
	back = current;
	while (back->prev && back->n < back->prev->n)
		{
		swap_nodes(list, back->prev, back);
		print_list(*list);
		}
	current = current->next;
	}
}
