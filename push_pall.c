#include "monty.h"


/**
 * push - pushes an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
        char *arg = strtok(NULL, " \n");
        int n;

        if (!arg || !isdigit(*arg) && *arg != '-' && *arg != '+') {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
        }

        n = atoi(arg);
        add_node(stack, n);
}

/**
 * pall - prints all the values on the stack, starting from the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
        stack_t *current = *stack;

        while (current) {
                printf("%d\n", current->n);
                current = current->next;
        }
}

/**
 * main - entry point for the program
 * @argc: number of arguments
 * @argv: array of argument strings
 *
 * Return: 0 on success, non-zero on failure
 */
int main(int argc, char *argv[])
{
        char *line = NULL;
        size_t len = 0;
        ssize_t nread;
        stack_t *stack = NULL;
        instruction_t opcodes[] = {
                {"push", push},
                {"pall", pall},
                {NULL, NULL}
        };
        unsigned int line_number = 0;

        if (argc != 2) {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }

        FILE *file = fopen(argv[1], "r");
        if (!file) {
                fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
                exit(EXIT_FAILURE);
        }

        while ((nread = getline(&line, &len, file)) != -1) {
                char *opcode = strtok(line, " \n");

                line_number++;

                if (!opcode || opcode[0] == '#')
                        continue;

                for (instruction_t *op = opcodes; op->opcode; op++) {
                        if (strcmp(opcode, op->opcode) == 0) {
                                op->f(&stack, line_number);
                                break;
                        }
                }
        }

        free(line);
        fclose(file);

        return 0;
}
