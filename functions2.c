#include "monty.h"

/**
 * push - pushes data on top[ of the stack]
 * @stack: the head of the steck
 * @line_n: the current line opcode being executed
 * Return: void.
 */
void push(stack_t **stack, unsigned int line_n)
{
		stack_t *new;

		line_n += 1;

		new = createNode(data);

		if (*stack == NULL)
		{
				*stack = new;
		}
		else
		{
				new->next = *stack;
				(*stack)->prev = new;
				*stack = new;
		}

		line_n -= 1;
}

/**
 * pop - pops the top element of the stack
 * @stack: the head of the steck
 * @line_n: the current line opcode being executed
 * Return: void.
 */
void pop(stack_t **stack, unsigned int line_n)
{
		stack_t *temp;

		if (*stack == NULL)
		{
				fprintf(stderr, "L%u: can't pop an empty stack\n", line_n);
				exit(EXIT_FAILURE);
		}

		temp = *stack;

		*stack = (*stack)->next;

		if (*stack != NULL)
				(*stack)->prev = NULL;

		free(temp);
}

/**
 * pall - prints all the elements of the stack
 * @stack: the head of the steck
 * @line_n: the current line opcode being executed
 * Return: void.
 */
void pall(stack_t **stack, unsigned int line_n)
{
		stack_t *current;

		if (*stack == NULL)
		{
				fprintf(stderr, "Stack is empty.\n");
				return;
		}

		line_n += 1;

		current = *stack;

		line_n -= 1;

		while (current != NULL)
		{
				printf("%d\n", current->n);
				current = current->next;
		}
}

/**
 * add - adds the two elements of the stack together
 * @stack: the head of the steck
 * @line_n: the current line opcode being executed
 * Return: void.
 */
void add(stack_t **stack, unsigned int line_n)
{
		int sum;
		stack_t *temp;

		if (*stack == NULL || (*stack)->next == NULL)
		{
				fprintf(stderr, "L%d: can't add, stack too short\n", line_n);
				exit(EXIT_FAILURE);
		}

		sum = (*stack)->n + (*stack)->next->n;

		temp = *stack;

		*stack = (*stack)->next;
		(*stack)->n = sum;
		(*stack)->prev = NULL;

		free(temp);
}

/**
 * nop - doies nothing art all
 * @stack: the head of the steck
 * @line_n: the current line opcode being executed
 * Return: void.
 */
void nop(stack_t **stack, unsigned int line_n)
{

		(*stack)->n += line_n - line_n;

}
