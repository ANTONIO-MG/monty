#include "monty.h"

/**
 * open_file - opens the .m file with teh opcode
 * @filename: name of the file to be opened
 *
 * Return: void.
 */
void open_file(char *filename)
{
		FILE *file = fopen(filename, "r");

		if (file == NULL)
		{
				printf("Error: Can't open file %s\n", filename);
				exit(EXIT_FAILURE);
		}
		else
		{
				execute(file);
		}

		fclose(file);
}

/**
 * execute - executes the instructions in the opcode
 * @file: name of the file to be opened
 *
 * Return: void.
 */
void execute(FILE *file)
{
		char line[100];
		char *command;
		char *func;
		int data;
		int linenum = 0;
		stack_t *head = NULL;

		while (fgets(line, sizeof(line), file))
		{
				linenum++;
				command = strtok(line, " \t\r\n\a");
				if (command == NULL)
						continue;
				else if (strcmp(command, "pall") == 0)
				{
						head = pall(head);
						break;
				}
				func = command;
				command = strtok(NULL, "\t\r\n\a");
				data = atoi(command);

				head = run(func, data, head, linenum);
		}

		free_list(head);
}

/**
 * run - runs the specific command in the opcode
 * @func: the function to be executed
 * @data: data to be stored in the node
 * @head: the head of the list
 * @linenum: line number of the command being called
 *
 * Return: the head node.
 */
stack_t *run(char *func, int data, stack_t *head, int linenum)
{
		stack_t *temp_head = NULL;

		if (strcmp(func, "push") == 0)
		{
				temp_head = push(head, data, linenum);
		}

		return (temp_head);
}

/**
 * push - pushes the data to the top of the stack
 * @data: data to be stored in the node
 * @head: the head of the list
 * @linenum: line number of the command being called
 *
 * Return: the new node.
 */
stack_t *push(stack_t *head, int data, int linenum)
{
		stack_t *new = malloc(sizeof(stack_t));

		if (data == 0)
		{
				fprintf(stderr, "L%d: usage: push integer\n", linenum);
				exit(EXIT_FAILURE);
		}

		if (new == NULL)
		{
				fprintf(stderr, "malloc failed\n");
				exit(EXIT_FAILURE);
		}

		new->n = data;
		new->prev = NULL;
		new->next = head;

		if (head != NULL)
		{
				head->prev = new;
		}

		return (new);
}
