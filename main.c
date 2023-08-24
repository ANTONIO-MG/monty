#include "monty.h"

/**
 * main - executes the monty interpretor
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success and other numbers on failure.
 */
int main(int argc, char **argv)
{
		if (argc != 2)
		{
				fprintf(stderr, "USAGE: monty file\n");
				exit(EXIT_FAILURE);
		}

		open_file(argv[1]);

		return (0);
}
