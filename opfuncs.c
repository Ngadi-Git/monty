#include "monty.h"

/**
  * open_file - opens the file and feeds it into the command function
  *
  * @file_name: file name that was given
  * Return: 0 on success, exit on failure
  */
int open_file(char *file_name)
{
	unsigned int line_no = 0;

	glo.fp = fopen(file_name, "r");
	if (glo.fp == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	line_no = line_iterate(line_no);

	return (0);
}

/**
  * line_iterate - iterates through lines for commands
  *
  * @line_no: line number
  * Return: line number where function ends
  */
unsigned int line_iterate(unsigned int line_no)
{
	stack_t *stack = NULL;
	size_t bufsize;

	while (getline(&glo.buffer, &bufsize, glo.fp) != -1)
	{
		line_no++;
		opcode(&stack, line_no);
	}

	memory_clear(stack);

	return (line_no);
}

