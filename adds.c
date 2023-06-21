#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
* add - Adds the top
* @stack: Pointer to the top
*/
void add_s(stack_t **stack)
{
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "Error: can't add, stack too short\n");
exit(EXIT_FAILURE);
}
(*stack)->next->n += (*stack)->n;
pop_s(stack);
}

