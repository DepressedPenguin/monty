#include "monty.h"
/**
* push - Pushes an element
* @stack: Double pointer
* @value: Value
*/
void push_stack(stack_t **stack, int value)
{
stack_t *new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new_node->n = value;
new_node->prev = NULL;
new_node->next = *stack;
if (*stack != NULL)
(*stack)->prev = new_node;
*stack = new_node;
}

