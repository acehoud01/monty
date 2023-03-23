#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the instruction
 *
 * Return: Always return 0
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack)
	{
		(*stack)->prev = NULL;
	}
	free(tmp)
}
