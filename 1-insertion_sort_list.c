#include "sort.h"
/**
 * insertion_sort_list - sorts doubly linked list using the Insertion sort.
 * @list: head of linked list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev_node, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		next_node = current->next;
		prev_node = current->prev;

		while (prev_node != NULL && prev_node->n > current->n)
		{
			prev_node->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev_node;
			current->next = prev_node;
			current->prev = prev_node->prev;
			if (prev_node->prev != NULL)
				prev_node->prev->next = current;
			else
				*list = current;

			prev_node->prev = current;
			prev_node = current->prev;
			print_list(*list);
		}
		current = next_node;
	}
}
