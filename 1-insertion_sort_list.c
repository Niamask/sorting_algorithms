#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers ascending order
 * in ascending order using the Insertion sort algorithm.
 * @list: given dl list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *t;

	if (!list)
		return;

	for (current = *list; current; current = current->next)
	{
		while (current->next && (current->next->n < current->n))
		{
			t = current->next;
			current->next = t->next;
			t->prev = current->prev;

			if (current->prev)
				current->prev->next = t;

			if (t->next)
				t->next->prev = current;

			current->prev = t;
			t->next = current;

			if (t->prev)
				current = t->prev;
			else
				*list = t;

			print_list(*list);
		}
	}
}
