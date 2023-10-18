/**
  * push_help - helper function for push
  *
  * @stack: first element of the stack
  * @new_element: element to add
  * Return: void
  */
void push_help(stack_t **stack, stack_t *new_element)
{
	stack_t *tmp;

	if (glo.mode == 0)
	{
		tmp = *stack;
		new_element->next = tmp;
		*stack = new_element;
		if (tmp)
			tmp->prev = *stack;
	}
	else
	{
		stoq(stack, 0);
		tmp = *stack;
		new_element->next = tmp;
		if (tmp)
			tmp->prev = new_element;
		*stack = new_element;
		stoq(stack, 0);
	}
}
