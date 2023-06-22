#include <stdio.h>
#include "monty.h"
/**
* pstr - Prints the string
* @stack: Pointer to the top stack
*/
void ps_tr(stack_t **stack)
{
stack_t *current = *stack;
while (current != NULL && current->n != 0 && current->n >= 32 && current->n <= 127)
{
printf("%c", current->n);
current = current->next;
}
printf("\n");
}

