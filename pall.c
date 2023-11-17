#include "monty.h"
/**
 * func_pall - prints the stack
 * @headers: stack head
 * @counts: no used
 * Return: no return
*/
void func_pall(stack_t **headers, unsigned int counts)
{
	stack_t *m;
	(void)counts;

	m = *headers;
	if (m == NULL)
		return;
	while (m)
	{
		printf("%d\n", m->n);
		m = m->next;
	}
}
