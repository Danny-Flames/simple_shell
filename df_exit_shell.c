#include "main.h"

/**
 * exit_shell - To exit the shell
 *
 * @data_args: the data relevant (status and args)
 * Return: 0 on success.
 */
int exit_shell(data_shell *data_args)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int big_number;

	if (data_args->args[1] != NULL)
	{
		ustatus = _atoi(data_args->args[1]);
		is_digit = _isdigit(data_args->args[1]);
		str_len = _strlen(data_args->args[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			get_error(data_args, 2);
			data_args->status = 2;
			return (1);
		}
		data_args->status = (ustatus % 256);
	}
	return (0);
}
