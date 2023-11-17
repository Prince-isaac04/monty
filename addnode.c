#include "monty.h"
/**
 * addnodes - add node to the head stack
 * @headers: head of the stack
 * @v: new_value
 * Return: no return
*/
void addnodes(stack_t **headers, int v)
{

	stack_t *top, *new_nod;

	top = *headers;
	new_nod = malloc(sizeof(stack_t));
	if (new_nod == NULL)
	{ printf("Error\n");
		exit(0); }
	if (top)
		top->prev = new_nod;
	new_nod->n = v;
	new_nod->next = *headers;
	new_nod->prev = NULL;
	*headers = new_nod;
}
