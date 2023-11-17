#include "monty.h"
/**
 * func_push - add node to the stack
 * @head: stack head
 * @counts: line_number
 * Return: no return
 */
void func_push(stack_t **head, unsigned int counts)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counts);
			fclose(bus.file);
			free(bus.content);
			remove_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counts);
		fclose(bus.file);
		free(bus.content);
		remove_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnodes(head, n);
	else
		queue_add(head, n);
}
