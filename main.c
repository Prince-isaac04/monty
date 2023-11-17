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
	char *buff;
	FILE *fd;
	ssize_t scan_line = 1;
	size_t sizes = 0;

	if (arg_counts != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(arg_v[1], "r");
	bus.fd = fd;
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arg_v[1]);
		exit(EXIT_FAILURE);
	}
	while (scan_line > 0)
	{
		buff = NULL;
		scan_line = getline(&buff, &sizes, fd);
		bus.buff = buff;
		counts++;
		if (scan_line > 0)
		{
			execute(buff, &stacks, counts, fd);
		}
		free(buff);
	}
	free_stack(stacks);
	fclose(fd);
	return (0);
}
