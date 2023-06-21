#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
* free_stack - Frees a stack
* @stack: Pointer to the top s
*/
void free_stack(stack_t *stack)
{
stack_t *tmp;

while (stack != NULL)
{
tmp = stack;
stack = stack->next;
free(tmp);
}
}

/**
* process_file - Processes a Monty
* @filename: Name of the Monty
* @stack: Pointer to the top stack
*/
void process_file(const char *filename, stack_t **stack)
{
FILE *file;
char line[1024];
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

if (opcode != NULL && opcode[0] != '#')
{
    if (strcmp(opcode, "push") == 0)
    {
	if (arg != NULL)
	{
	    int value;
	    if (sscanf(arg, "%d", &value) == 1)
		push(stack, value);
	    else
	    {
		fprintf(stderr, "Error: L%d: usage: push integer\n", line_number);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	    }
	}
	else
	{
	    fprintf(stderr, "Error: L%d: usage: push integer\n", line_number);
	    fclose(file);
	    free_stack(*stack);
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
	fclose(file);
	free_stack(*stack);
	exit(EXIT_FAILURE);
    }
}
line_number++;
}

fclose(file);
}
