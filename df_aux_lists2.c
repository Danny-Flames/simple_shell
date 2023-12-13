#include "main.h"

/**
 * add_rvar_node - this adds a variable at the end
 * of a r_var list.
 * @head: head of the linked list.
 * @lvar: length of the variable.
 * @val: value of the variable.
 * @lval: length of the value.
 * Return: address of the head.
 */
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
	r_var *new, *temp_var;

	new = malloc(sizeof(r_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

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
 * free_rvar_list - frees a r_var list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_rvar_list(r_var **head)
{
	r_var *temp_var;
	r_var *curr;

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
