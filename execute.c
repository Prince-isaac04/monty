#include "monty.h"
/**
* implement- executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int implement(char *buff, stack_t **stacks, unsigned int counts, FILE *fd)
{
	instruction_t opst[] = {
				{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{"nop", f_nop},
				{"sub", f_sub},
				{"div", f_div},
				{"mul", f_mul},
				{"mod", f_mod},
				{"pchar", f_pchar},
				{"pstr", f_pstr},
				{"rotl", f_rotl},
				{"rotr", f_rotr},
				{"queue", f_queue},
				{"stack", f_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *opd;

	opd = strtok(content, " \n\t");
	if (opd && opd[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(opd, opst[i].opcode) == 0)
		{	opst[i].f(stacks, counts);
			return (0);
		}
		i++;
	}
	if (opd && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, opd);
		fclose(fd);
		free(buff);
		free_stack(*stacks);
		exit(EXIT_FAILURE); }
	return (1);
}
