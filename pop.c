#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
* pop - Removes the top element
* @stack: Pointer to the top
*/
void pop(stack_t **stack)
{
stack_t *tmp;

if (*stack == NULL)
{
fprintf(stderr, "Error: can't pop an empty stack\n");
exit(EXIT_FAILURE);
}
tmp = *stack;
*stack = (*stack)->next;
if (*stack != NULL)
(*stack)->prev = NULL;
free(tmp);
}
