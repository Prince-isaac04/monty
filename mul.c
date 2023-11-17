#include "monty.h"
/**
 * func_mul - multiplies the top two elements of the stack.
 * @headers: stack head
 * @counts: line_number
 * Return: no return
 */
void func_mul(stack_t **headers, unsigned int counts)
{
	stack_t *m;
	int lent = 0, top;

	m = *headers;
	while (m)
	{
		m = m->next;
		lent++;
	}
	if (lent < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counts);
		fclose(bus.fd);
		free(bus.buff);
		free_stack(*headers);
		exit(EXIT_FAILURE);
	}
	m = *headers;
	top = m->next->n * m->n;
	m->next->n = top;
	*headers = m->next;
	free(m);
}
