#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
* main - Entry point
* @argc: Number of cmd args
* @argv: Array of args
*
* Return: 0 on success or fail
*/
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
process_f(filename, &stack);
return 0;
}

