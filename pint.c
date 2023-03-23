#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: pointer to the top of the stack
 * @line_number: the line number in the file
 *
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
