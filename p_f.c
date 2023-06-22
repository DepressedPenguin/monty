#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
* process_f - Processes a Monty 
* @filename: Name of the Monty file
* @stack: Pointer
*/
void process_f(const char *filename, stack_t **stack)
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
		push_stack(stack, value);
	    else
	    {
		fprintf(stderr, "Error: L%d: usage: push integer\n", line_number);
		fclose(file);
		free_s(*stack);
		exit(EXIT_FAILURE);
	    }
	}
	else
	{
	    fprintf(stderr, "Error: L%d: usage: push integer\n", line_number);
	    fclose(file);
	    free_s(*stack);
	    exit(EXIT_FAILURE);
	}
    }
    else if (strcmp(opcode, "pall") == 0)
    {
	pall_p(stack);
    }
    else if (strcmp(opcode, "pint") == 0)
    {
	sint(stack);
    }
    else if (strcmp(opcode, "pop") == 0)
    {
	pop_s(stack);
    }
    else if (strcmp(opcode, "swap") == 0)
    {
	swap_swap(stack);
    }
    else if (strcmp(opcode, "add") == 0)
    {
	add_s(stack);
    }
    else if (strcmp(opcode, "nop") == 0)
    {
	nop_g(stack);
    }
    else if (strcmp(opcode, "pstr") == 0)
    {
	ps_tr(stack);
    }
    else
    {
	fprintf(stderr, "Error: L%d: unknown instruction %s\n", line_number, opcode);
	fclose(file);
	free_s(*stack);
	exit(EXIT_FAILURE);
    }
}
line_number++;
}

fclose(file);
free_s(*stack);
}

/**
* free_s - Frees the stack
* @stack: Pointe
*/
void free_s(stack_t *stack)
{
stack_t *current = stack;
stack_t *next;

while (current != NULL)
{
next = current->next;
free(current);
current = next;
}
}

