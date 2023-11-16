#include "monty.h"
/**
 * func_pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 * @counts: line_number
 * Return: no return
 */
void func_pstr(stack_t **head, unsigned int counts)
{
	stack_t *h;
	(void)counts;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
