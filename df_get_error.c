#include "main.h"

/**
 * get_error -this will call the error according the builtin, syntax or permission
 * @data_args: data structure that contains arguments
 * @eval: the returned error value
 * Return: to return the error
 */
int get_error(data_shell *data_args, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = error_env(data_args);
		break;
	case 126:
		error = error_path_126(data_args);
		break;
	case 127:
		error = error_not_found(data_args);
		break;
	case 2:
		if (_strcmp("exit", data_args->args[0]) == 0)
			error = error_exit_shell(data_args);
		else if (_strcmp("cd", data_args->args[0]) == 0)
			error = error_get_cd(data_args);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	data_args->status = eval;
	return (eval);
}
