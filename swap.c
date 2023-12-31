#include "monty.h"
/**
 * func_swap - adds the top two elements of the stack.
 * @head: stack head
 * @counts: line_number
 * Return: no return
 */
void func_swap(stack_t **head, unsigned int counts)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counts);
		fclose(bus.file);
		free(bus.content);
		remove_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
