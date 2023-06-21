#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
* pint - Prints the value
* @stack: Pointer to the top
*/
void sint(stack_t **stack)
{
if (*stack == NULL)
{
fprintf(stderr, "Error: can't pint, stack empty\n");
exit(EXIT_FAILURE);
}

printf("%d\n", (*stack)->n);
}

