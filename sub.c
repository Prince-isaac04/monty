#include "monty.h"
/**
 *func_sub- sustration
 *@head: stack head
 *@counts: line_number
 *Return: no return
 */
void func_sub(stack_t **head, unsigned int counts)
{
	stack_t *aux;
	int sus, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counts);
		fclose(bus.file);
		free(bus.content);
		remove_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}
