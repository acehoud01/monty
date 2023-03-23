#include "monty.h"

/**
 * push - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */

void push(stack_t **stack, unsigned int line_number)
{
    char *token;
    int n;
    token = strtok(NULL, " \n\t");
    if (token == NULL || !isdigit(*token))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    n = atoi(token);
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = n;
    new_node->prev = NULL;
    if (*stack == NULL)
    {
        new_node->next = NULL;
    }
    else
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
    *stack = new_node;
}


