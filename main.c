#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
 * main - monty code interpreter
 * @arg_counts: number of arguments
 * @arg_v: monty file location
 * Return: 0 on success
 */
int main(int arg_counts, char *arg_v[])
{
	unsigned int counts = 0;
	stack_t *stacks = NULL;
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;

	if (arg_counts != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(arg_v[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arg_v[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.content = content;
		counts++;
		if (read_line > 0)
		{
			implement(content, &stacks, counts, file);
		}
		free(content);
	}
	remove_stack(stacks);
	fclose(file);
	return (0);
}
