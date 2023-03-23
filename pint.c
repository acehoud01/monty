#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: pointer to the top of the stack
 * @line_number: the line number in the file
 *
 * Return: void
 */

void pint(stack_t **stk, unsigned int number)
{
	if (*stk == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stk);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stk)->n);
}
