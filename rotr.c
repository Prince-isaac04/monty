#include "monty.h"
/**
 *func_rotr - rotates the stack to the bottom
 *@head: stack head
 *@counts: line_number
 *Return: no return
 */
void func_rotr(stack_t **head, __attribute__((unused)) unsigned int counts)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
