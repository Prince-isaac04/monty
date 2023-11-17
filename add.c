#include "monty.h"
/**
 * func_add - adds the top two elements of the stack.
 * @headers: stack head
 * @counts: line_number
 * Return: no return
 */
void func_add(stack_t **headers, unsigned int counts)
{
	int lent = 0, aus;
	stack_t *m;

	m = *headers;
	while (m)
	{
		m = m->next;
		lent++;
	}
	if (lent < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counts);
		fclose(bus.file);
		free(bus.content);
		remove_stack(*headers);
		exit(EXIT_FAILURE);
	}
	m = *headers;
	aus = m->n + m->next->n;
	m->next->n = aus;
	*headers = m->next;
	free(m);
}
