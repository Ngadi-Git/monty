#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * struct externVar - structure to use with buffer and file descriptor
 * @bfr: Memory buffer to store getline
 * @form: form to represent stack or queue
 * @fds: file descriptor for our file
 *
 * Descritpion: enables the utilization and release of specific variables employed in
 * in stack, queues, LIFO, FIFO Holberton project
 */
struct	externVar 
{
	char *bfr;
	int form;
	FILE *fds;
};

extern struct externVar ext;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* monty.c functions */
unsigned int line_iterate(unsigned int);
void opcode(stack_t **, unsigned int);

/* memory.c functions */
stack_t *malloc_stack(stack_t *);
void free_stack(stack_t *);
void memory_clear(stack_t *);

/* opbasic.c functions */
void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);

/* opmore.c functions */
void swap(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void divi(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);

/* opthree.c functions */
void mod(stack_t **, unsigned int);
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void stoq(stack_t **, unsigned int);

/* opfour.c functions */
void rotr(stack_t **, unsigned int);
void stac(stack_t **, unsigned int);
void queue(stack_t **, unsigned int);
void push_help(stack_t **, stack_t *);

#endif /*_MONTY_H_*/
