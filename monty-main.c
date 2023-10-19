#include "monty.h"

struct global_var glo = {NULL, 0, 0};

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

	file_open(argv[1]);

	return (EXIT_SUCCESS);
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

	token = strtok(glo.buffer, " \n\r\t");
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
