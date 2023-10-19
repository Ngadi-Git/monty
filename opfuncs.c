#include "monty.h"

/**
  * open_file - opens the file and feeds it into the command function
  *
  * @file_name: file name that was given
  * Return: 0 on success, exit on failure
  */
int file_open(char *file_n)
{
	unsigned int line = 0;

	ext.fp = fopen(file_n, "r");
	if (ext.fp == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file_n);
		exit(EXIT_FAILURE);
	}

	line = iterate_ln(line);

	return (0);
}

/**
  * line_iterate - iterates through lines for commands
  *
  * @line_no: line number
  * Return: line number where function ends
  */
unsigned int iterate_ln(unsigned int ln)
{
	stack_t *stack = NULL;
	size_t bufsize;

	while (getline(&ext.bfr, &bufsize, ext.fp) != -1)
	{
		ln++;
		opcode(&stack, ln);
	}

	memory_clear(stack);

	return (ln);
}

