#include "monty.h"

/**
 * pall_fun - prints all the values on the stack
 * @stack: pointer to the stack
 * @line_number: line number where the pall instruction appears
 */

void pall_fun(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	stack_t *used = *stack;

	while (used != NULL)
	{
		printf("%d\n", used->n);
		used = used->next;
	}
}
