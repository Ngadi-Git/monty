#include "monty.h"

struct externVar ext = {NULL, 0, 0};

/**
  * main - Takes in arguments and attempts to interpret monty code
  *
  * @argc: number of arguments
  * @argv: array of string arguments
  * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
  */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}


	unsigned int line_no;

	ext.fds = fopen(argv[1], "r");
	if (ext.fds == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	stack_t *stack = NULL;
	size_t bufsize;

	while (getline(&ext.bfr, &bufsize, ext.fds) != -1)
	{
		line_no++;
		opcode(&stack, line_no);
	}

	memory_clear(stack);

	return (line_no);
}

/**
  * opcode - searches and runs possible opcode commands
  *
  * @stack: first element of stack
  * @line_no: line number
  * Return: void
  */
void opcode(stack_t **stack, unsigned int line_no)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divi},
		{"mul", mul},
		{"mod", mod},
		{"rotl", rotl},
		{"rotr", rotr},
		{"pchar", pchar},
		{"pstr", pstr},
		{"queue", queue},
		{"stack", stac},
		{NULL, NULL}
	};
	int i = 0;
	char *token;

	token = strtok(ext.bfr, " \n\r\t");
	if (token == NULL || *token == '#')
		return;

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcodes[i].opcode, token) == 0)
			break;
		i++;
	}
	if (opcodes[i].opcode == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_no, token);
		memory_clear(*stack);
		exit(EXIT_FAILURE);
	}
	opcodes[i].f(stack, line_no);
}
