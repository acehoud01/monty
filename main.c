#include "monty.h"
#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * main - Entry point for monty
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL, *opcode = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	fp = fopen(filename, "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, fp)) != -1)
	{
		line_number++;
		if (*line == '\n' || *line == '#')
			continue;
		execute_opcode(line, &stack, line_number);
	}

	free_stack(stack);
	if (line)
		free(line);
	fclose(fp);

	return (0);
}
