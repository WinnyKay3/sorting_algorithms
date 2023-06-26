#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order usung insertion algorithm
 * @list: double linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prevprev, *prev, *current1, *currentnext;

	if (list == NULL)
		return;

	current = *list;

	while (current)
	{
		if (current->prev && current->prev->n > current->n)
		{
			prevprev = current->prev->prev;
			prev = current->prev;
			current1 = current;
			currentnext = current->next;

			prev->next = currentnext;

			if (currentnext)
				currentnext->prev = prev;
			current1->prev = prevprev;
			current1->next = prev;

			if (prevprev)
				prevprev->next = current1;
			else
				*list = current1;

			prev->prev = current1;
			current = *list;
			print_list(*list);
			continue;
		}
		else
			current = current->next;
	}
}
