#include "monty.h"

/**
 * main - the monty interpretor
 * @argc: argument cout
 * @argv: argument vectors
 * Return: 0 on sucess and other number on error
 */
int main(int argc, char **argv)
{
		FILE *file;
		char line[100], opcode[100];
		unsigned int line_n = 0;
		stack_t *stack = NULL;
		instruction_t inst[] = {
				{"push", push},
				{"pop", pop},
				{"pall", pall},
				{"swap", swap},
				{"add", add},
				{"pint", pint},
				{"nop", nop}
		};

		if (argc != 2) 
		{
				fprintf(stderr, "USAGE: monty file\n");
				exit(EXIT_FAILURE);
		}

		file = fopen(argv[1], "r");

		if (file == NULL) 
		{
				fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
				exit(EXIT_FAILURE);
		}

		while (fgets(line, sizeof(line), file))
		{
				line_n++;
				sscanf(line, "%[a-zAZ] %d", opcode, &data);
				execute(&stack, opcode, line_n, inst);
		}
		free_list(stack);
		fclose(file);

		return (0);
}

