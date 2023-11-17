#include "monty.h"
/**
 * func_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @headers: stack head
 * @counts: line_number
 * Return: no return
*/
void func_mod(stack_t **headers, unsigned int counts)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counts);
		fclose(bus.file);
		free(bus.content);
		remove_stack(*headers);
		exit(EXIT_FAILURE);
	}
	m = *headers;
	if (m->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counts);
		fclose(bus.file);
		free(bus.content);
		remove_stack(*headers);
		exit(EXIT_FAILURE);
	}
	top = m->next->n % m->n;
	m->next->n = top;
	*headers = m->next;
	free(m);
}
