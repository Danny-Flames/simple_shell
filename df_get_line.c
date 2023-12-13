#include "main.h"

/**
 * bring_line - To assign the line var for get_line
 * @line_ptr: The buffer that store the input str
 * @buffer: The str that is been called to line
 * @n: the size of line
 * @j: the size of buffer
 */
void bring_line(char **line_ptr, size_t *n, char *buffer, size_t j)
{

	if (*line_ptr == NULL)
	{
		if  (j > BUFSIZE)
			*n = j;

		else
			*n = BUFSIZE;
		*line_ptr = buffer;
	}
	else if (*n < j)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*line_ptr = buffer;
	}
	else
	{
		_strcpy(*line_ptr, buffer);
		free(buffer);
	}
}
/**
 * get_line - To Read inpt from stream
 * @line_ptr: buffer that stores the input
 * @n: size of line_ptr
 * @stream: stream to read from
 * Return: The number of bytes
 */
ssize_t get_line(char **line_ptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t retval;
	char *buffer;
	char t = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input] = t;
		input++;
	}
	buffer[input] = '\0';
	bring_line(line_ptr, n, buffer, input);
	retval = input;
	if (i != 0)
		input = 0;
	return (retval);
}
