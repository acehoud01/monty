#include "monty.h"

/**
 * push - pushes an element onto the stack
 * @stack: pointer to the stack
 * @line_number: line number where the push instruction appears
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg;
    int val;

    arg = strtok(NULL, " \n");
    if (arg == NULL || !isdigit(*arg) && *arg != '-')
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    val = atoi(arg);
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = val;
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack != NULL)
        (*stack)->prev = new_node;
    *stack = new_node;
}
