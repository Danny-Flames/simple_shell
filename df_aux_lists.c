#include "main.h"

/**
 * add_sep_node_end - this adds a separator found at the end
 * of a sep_list.
 * @head: the head of the linked list.
 * @sep: the separator found (; | &).
 * Return: address of the head.
 */
sep_list *add_sep_node_end(sep_list **head, char sep)
{
	sep_list *new, *temp_var;

	new = malloc(sizeof(sep_list));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
	new->next = NULL;
	temp_var = *head;

	if (temp_var == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp_var->next != NULL)
			temp_var = temp_var->next;
		temp_var->next = new;
	}

	return (*head);
}

/**
 * free_sep_list - frees a sep_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_sep_list(sep_list **head)
{
	sep_list *temp_var;
	sep_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp_var = curr) != NULL)
		{
			curr = curr->next;
			free(temp_var);
		}
		*head = NULL;
	}
}

/**
 * add_line_node_end - adds a command line at the end
 * of a line_list.
 * @head: head of the linked list.
 * @line: command line.
 * Return: address of the head.
 */
line_list *add_line_node_end(line_list **head, char *line)
{
	line_list *new, *temp_var;

	new = malloc(sizeof(line_list));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	temp_var = *head;

	if (temp_var == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp_var->next != NULL)
			temp_var = temp_var->next;
		temp_var->next = new;
	}

	return (*head);
}

/**
 * free_line_list - frees a line_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_line_list(line_list **head)
{
	line_list *temp_var;
	line_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp_var = curr) != NULL)
		{
			curr = curr->next;
			free(temp_var);
		}
		*head = NULL;
	}
}
