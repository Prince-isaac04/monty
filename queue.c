#include "monty.h"
/**
 * func_queue - prints the top
 * @head: stack head
 * @counts: line_number
 * Return: no return
 */
void func_queue(stack_t **head, unsigned int counts)
{
	(void)head;
	(void)counts;
	bus.lifi = 1;
}

/**
 * queue_add - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
 */
void queue_add(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
