#include "main.h"

/**
 * exec_line - To find builtins and commands
 *
 * @data_args: data relevant (args)
 * Return: 1 on success.
 */
int exec_line(data_shell *data_args)
{
	int (*builtin)(data_shell *data_args);

	if (data_args->args[0] == NULL)
		return (1);

	builtin = get_builtin(data_args->args[0]);

	if (builtin != NULL)
		return (builtin(data_args));

	return (cmd_exec(data_args));
}
