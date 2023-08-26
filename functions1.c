#include "monty.h"

/**
 * pint - prints the data on the stack
 * @stack: the head of the list
 * @line_n: the current opcode line number
 * Return: the head node.
 */
void pint(stack_t **stack, unsigned int line_n)
{
		if (*stack == NULL)
		{
				fprintf(stderr, "L%d: can't print, stack empty\n", line_n);
				exit(EXIT_FAILURE);
		}

		printf("%d\n", (*stack)->n);
}

/**
 * execute - executes the given op code
 * @stack: the head of the list
 * @opcode: the opcode to be executed
 * @line_n: the current opcode line
 * @inst: the instructiuon struct to match
 * Return: the head node.
 */
void execute(stack_t **stack, char *opcode, int line_n, instruction_t inst[])
{
		int i = 0;
		int check = 0;

		while (i < 7)
		{
				if (strcmp(inst[i].opcode, opcode) == 0)
				{
					inst[i].f(stack, line_n);
						check = 1;
				}
				i++;
		}

		if ((check != 1))
		{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_n, opcode);
		}

}

/**
 * createNode - creates a node
 * @data: the bdata to be passed to the new node
 * Return: void.
 */
stack_t *createNode(int data)
{
		stack_t *new_node = malloc(sizeof(stack_t));

		if (new_node == NULL)
		{
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
		}

		new_node->n = data;
		new_node->prev = NULL;
		new_node->next = NULL;

		return (new_node);
}

/**
 * free_list - free's the doubly linked list completely
 * @stack: the head of the steck
 * @line_n: the current line opcode being executed
 * Return: void.
 */
void free_list(stack_t *head)
{

		stack_t *next_node;

		if (head == NULL)
				exit(EXIT_SUCCESS);

		while (head->prev != NULL)
				head = head->prev;

		while (head != NULL)
		{
				next_node = head->next;
				free(head);
				head = next_node;
		}
}

/**
 * swap - swaps the top two elements of teh stack
 * @stack: the head of the steck
 * @line_n: the current line opcode being executed
 * Return: void.
 */
void swap(stack_t **stack, unsigned int line_n)
{
		stack_t *first_num;
		stack_t *second_num;

		if (*stack == NULL || (*stack)->next == NULL)
		{
				fprintf(stderr, "L%d: can't swap, stack too short\n", line_n);
				exit(EXIT_FAILURE);
		}

		first_num = *stack;
		second_num = (*stack)->next;

		if (first_num->prev)
				first_num->prev->next = second_num;
		if (second_num->next)
				second_num->next->prev = first_num;

		first_num->next = second_num->next;
		second_num->prev = first_num->prev;
		first_num->prev = second_num;
		second_num->next = first_num;

		*stack = second_num;
}
