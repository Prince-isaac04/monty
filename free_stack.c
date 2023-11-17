#include "monty.h"
/**
 * remove_stack - frees a doubly linked list
 * @headers: head of the stack
 */
void remove_stack(stack_t *headers)
{
	stack_t *top;

	top = headers;
	while (headers)
	{
		top = headers->next;
		free(headers);
		headers = top;
	}
}
