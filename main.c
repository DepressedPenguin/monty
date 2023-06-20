/* main.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

void process_file(const char *filename, stack_t **stack)
{
    FILE *file;
    char line[100];
    int line_number = 1;
    char *opcode;
    char *arg;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    while (fgets(line, sizeof(line), file))
    {
        line[strcspn(line, "\n")] = '\0';
        opcode = strtok(line, " ");
        arg = strtok(NULL, " ");
        if (opcode != NULL)
        {
            if (strcmp(opcode, "push") == 0)
            {
                if (arg != NULL)
                {
                    int value = atoi(arg);
                    push(stack, value);
                }
                else
                {
                    fprintf(stderr, "Error: L%d: usage: push integer\n", line_number);
                    exit(EXIT_FAILURE);
                }
            }
            else if (strcmp(opcode, "pall") == 0)
            {
                pall(stack);
            }
            else
            {
                fprintf(stderr, "Error: L%d: unknown instruction %s\n", line_number, opcode);
                exit(EXIT_FAILURE);
            }
        }
        line_number++;
    }
    fclose(file);
}

int main(int argc, char *argv[])
{
    const char *filename;
    stack_t *stack = NULL;
    if (argc != 2)
    {
        fprintf(stderr, "Usage: monty file\n");
        exit(EXIT_FAILURE);
    }
    filename = argv[1];
    process_file(filename, &stack);
    return 0;
}

