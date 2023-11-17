#include "monty.h"
/**
* implement - executes the opcode
* @stacks: head linked list - stack
* @counts: line_counter
* @fd: poiner to monty file
* @buff: line content
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
	char *code;
	unsigned int i = 0;

	code = strtok(buff, " \n\t");
	if (code && code[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && code)
	{
		if (strcmp(code, opst[i].opcode) == 0)
		{	opst[i].f(stacks, counts);
			return (0);
		}
		i++;
	}
	if (code && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counts, code);
		fclose(f);
		free(content);
		free_stack(*stacks);
		exit(EXIT_FAILURE); }
	return (1);
}
