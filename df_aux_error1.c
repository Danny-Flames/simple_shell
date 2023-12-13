
#include "main.h"

/**
 * strcat_cd - This is the function that concatenates the message for cd sys_cust_err
 *
 * @datash: for the data relevant (directory)
 * @msg: for the message to print
 * @sys_cust_err: the output message
 * @ver_str: the counter lines
 * Return: the sys_cust_err message
 */
char *strcat_cd(data_shell *datash, char *msg, char *sys_cust_err, char *ver_str)
{
	char *illegal_flag;

	_strcpy(sys_cust_err, datash->av[0]);
	_strcat(sys_cust_err, ": ");
	_strcat(sys_cust_err, ver_str);
	_strcat(sys_cust_err, ": ");
	_strcat(sys_cust_err, datash->args[0]);
	_strcat(sys_cust_err, msg);
	if (datash->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = datash->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(sys_cust_err, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(sys_cust_err, datash->args[1]);
	}

	_strcat(sys_cust_err, "\n");
	_strcat(sys_cust_err, "\0");
	return (sys_cust_err);
}

/**
 * error_get_cd - the sys_cust_err message for cd command in get_cd
 * @datash:the  data relevant (directory)
 * Return: the Error message
 */
char *error_get_cd(data_shell *datash)
{
	int length, len_id;
	char *sys_cust_err, *ver_str, *msg;

	ver_str = aux_itoa(datash->counter);
	if (datash->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _strlen(datash->args[1]);
	}

	length = _strlen(datash->av[0]) + _strlen(datash->args[0]);
	length += _strlen(ver_str) + _strlen(msg) + len_id + 5;
	sys_cust_err = malloc(sizeof(char) * (length + 1));

	if (sys_cust_err == 0)
	{
		free(ver_str);
		return (NULL);
	}

	sys_cust_err = strcat_cd(datash, msg, sys_cust_err, ver_str);

	free(ver_str);

	return (sys_cust_err);
}

/**
 * error_not_found - generic sys_cust_err message for command not found
 * @datash: the data relevant (counter, arguments)
 * Return: the Error message
 */
char *error_not_found(data_shell *datash)
{
	int length;
	char *sys_cust_err;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + 16;
	sys_cust_err = malloc(sizeof(char) * (length + 1));
	if (sys_cust_err == 0)
	{
		free(sys_cust_err);
		free(ver_str);
		return (NULL);
	}
	_strcpy(sys_cust_err, datash->av[0]);
	_strcat(sys_cust_err, ": ");
	_strcat(sys_cust_err, ver_str);
	_strcat(sys_cust_err, ": ");
	_strcat(sys_cust_err, datash->args[0]);
	_strcat(sys_cust_err, ": not found\n");
	_strcat(sys_cust_err, "\0");
	free(ver_str);
	return (sys_cust_err);
}

/**
 * error_exit_shell - the generic sys_cust_err message for exit in get_exit
 * @datash: for thedata relevant (counter, arguments)
 *
 * Return: Error message
 */
char *error_exit_shell(data_shell *datash)
{
	int length;
	char *sys_cust_err;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
	sys_cust_err = malloc(sizeof(char) * (length + 1));
	if (sys_cust_err == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(sys_cust_err, datash->av[0]);
	_strcat(sys_cust_err, ": ");
	_strcat(sys_cust_err, ver_str);
	_strcat(sys_cust_err, ": ");
	_strcat(sys_cust_err, datash->args[0]);
	_strcat(sys_cust_err, ": Illegal number: ");
	_strcat(sys_cust_err, datash->args[1]);
	_strcat(sys_cust_err, "\n\0");
	free(ver_str);

	return (sys_cust_err);
}
