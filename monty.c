#include "monty.h"

int main(int ac, char **av)
{
	char line[10];
	int linenum = 0;
	unsigned int num = 0;
	FILE *fd;
	instruction_t instructions_list[] = {
		{"push", &push},
		{"pall", &pall}};
	stack_t *head = NULL;

	if (ac < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else if ((fd = fopen(av[1], "r")) == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	printf("%s\n", av[1]);

	while (fscanf(fd, " %s", line) != EOF)
	{
		++linenum;

		if (strncmp(line, instructions_list[0].opcode, 4) == 0)
		{
			fscanf(fd, " %u", &num);
			instructions_list[0].f(&head, num);
		}
		else if (strncmp(line, instructions_list[1].opcode, 4) == 0)
			instructions_list[1].f(&head, num);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", linenum, line);
			exit(EXIT_FAILURE);
		}

		fscanf(fd, "%*[^\n]");
	}

	fclose(fd);
	free_stackt(head);

	return (0);
}
