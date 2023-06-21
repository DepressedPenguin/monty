#include "monty.h"
/**
* pall - Prints all the values
* @stack: Double pointer
*/
void pall(stack_t **stack)
{
stack_t *current = *stack;

while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}
