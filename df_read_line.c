#include "main.h"

/**
 * read_line - this reads the input string.
 *
 * @gt_line_eof: to return the value of getline function
 * Return: input string
 */
char *read_line(int *gt_line_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*gt_line_eof = getline(&input, &bufsize, stdin);

	return (input);
}
