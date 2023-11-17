#include "monty.h"
/**
* implement- executes the opcode
* @stacks: head linked list - stack
* @counts: line_counter
* @fd: poiner to monty file
* @buff: line content
* Return: no return
*/
int implement(char *buff, stack_t **stacks, unsigned int counts, FILE *fd)
{
	instruction_t opst[] = {
				{"push", func_push}, {"pall", func_pall}, {"pint", func_pint},
				{"pop", func_pop},
				{"swap", func_swap},
				{"add", func_add},
				{"nop", func_nop},
				{"sub", func_sub},
				{"div", func_div},
				{"mul", func_mul},
				{"mod", func_mod},
				{"pchar", func_pchar},
				{"pstr", func_pstr},
				{"rotl", func_rotl},
				{"rotr", func_rotr},
				{"queue", func_queue},
				{"stack", func_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *opd;

	opd = strtok(buff, " \n\t");
	if (opd && opd[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && opd)
	{
		if (strcmp(opd, opst[i].opcode) == 0)
		{	opst[i].f(stacks, counts);
			return (0);
		}
		i++;
	}
	if (opd && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counts, opd);
		fclose(fd);
		free(buff);
		remove_stack(*stacks);
		exit(EXIT_FAILURE); }
	return (1);
}
