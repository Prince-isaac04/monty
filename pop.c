#include "monty.h"
/**
 * func_pop - prints the top
 * @head: stack head
 * @counts: line_number
 * Return: no return
 */
void func_pop(stack_t **head, unsigned int counts)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counts);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
