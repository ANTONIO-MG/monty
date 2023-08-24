#include "monty.h"

/**
 * pall - prints the data on the stack
 * @head: the head of the list
 *
 * Return: the head node.
 */
stack_t *pall(stack_t *head)
{
		stack_t *mover = head;

		while (mover->next)
		{
				printf("%d\n", mover->n);
				mover = mover->next;
		}

		/*while (mover != NULL)
		{
				printf("%d\n", mover->n);
				mover = mover->prev;
		}*/

		return (head);
}

/**
 * free_list - frees the entire list
 * @head: the head of the list
 *
 * Return: void
 */
void free_list(stack_t *head)
{
		if (head == NULL)
				return;

		/* Traverse to the head node */
		while (head->prev != NULL)
				head = head->prev;

		/* Free all nodes in the linked list*/
		while (head != NULL)
		{
				stack_t *next_node = head->next;

				free(head);
				head = next_node;
		}
}
