#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *item = malloc(sizeof(stack_t));
	stack_t *temp = *stack;

	if (item == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	item->n = line_number;
	item->next = NULL;

	if ((*stack) == NULL)
	{
		item->prev = NULL;
		(*stack) = item;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;

		item->prev = temp;
		temp->next = item;
		(*stack) = item;
	}
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
	printf("%d because\n", line_number);
}

void free_stackt(stack_t *current)
{
	stack_t *temp;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}
