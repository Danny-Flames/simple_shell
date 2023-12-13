#include "main.h"

/**
 * error_env - for the sys_cust_err message for env in get_env.
 * @datash: the  data relevant (counter, arguments)
 * Return:  the sys_cust_err message.
 */
char *error_env(data_shell *datash)
{
	int length;
	char *sys_cust_err;
	char *ver_str;
	char *msg;

	ver_str = aux_itoa(datash->counter);
	msg = ": Unable to add/remove from environment\n";
	length = _strlen(datash->av[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + _strlen(msg) + 4;
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
	_strcat(sys_cust_err, msg);
	_strcat(sys_cust_err, "\0");
	free(ver_str);

	return (sys_cust_err);
}
/**
 * error_path_126 - the sys_cust_err message for path and failure denied permission.
 * @datash: the data relevant (counter, arguments).
 *
 * Return: To return the sys_cust_err string.
 */
char *error_path_126(data_shell *datash)
{
	int length;
	char *ver_str;
	char *sys_cust_err;

	ver_str = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + 24;
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
	_strcat(sys_cust_err, ": Permission denied\n");
	_strcat(sys_cust_err, "\0");
	free(ver_str);
	return (sys_cust_err);
}
