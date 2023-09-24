#include "sort.h"

/**
 * insertion_sort_list -  sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: doubly linked list to sort
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *next, *prev;

	if (list == NULL || *list == NULL)
		return;

	curr = *list;
	next = curr->next;

	while (next != NULL)
	{
		while (curr->prev != NULL && curr->n > next->n)
		{
			prev = curr->prev;
			curr->next = next->next;
			next->prev = prev;
			curr->prev = next;
			next->next = curr;

			if (curr->next != NULL)
				curr->next->prev = curr;

			if (next->prev != NULL)
				next->prev->next = next;

			if (next->prev == NULL)
				*list = next;

			print_list(*list);
			curr = next->prev;
		}
		curr = next;
		next = next->next;
	}
}
