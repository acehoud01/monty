#include "monty.h"

/**
 * pall_fun - prints all the values on the stack
 * @stack: pointer to the stack
 * @line_number: line number where the pall instruction appears
 */

void pall_fun(stack_t **stk, unsigned int starter)
{
	(void) starter;

	stack_t *used = *stk;

	while (used != NULL)
	{
		printf("%d\n", used->n);
		used = used->next;
	}
}
