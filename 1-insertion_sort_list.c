#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the doubly linked list
 * @node_a: Pointer to the first node
 * @node_b: Pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *node_a, listint_t *node_b)
{
	node_a->next = node_b->next;
	if (node_b->next != NULL)
		node_b->next->prev = node_a;
	node_b->prev = node_a->prev;
	node_b->next = node_a;
	if (node_a->prev != NULL)
		node_a->prev->next = node_b;
	else
		*list = node_b;
	node_a->prev = node_b;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *pos, *temp;

	if (list == NULL || *list == NULL)
		return;

	pos = (*list)->next;
	while (pos != NULL)
	{
		temp = pos;
		pos = pos->next;
		while (temp->prev != NULL && temp->prev->n > temp->n)
		{
			swap_nodes(list, temp->prev, temp);
			print_list((const listint_t *)*list);
		}
	}
}
