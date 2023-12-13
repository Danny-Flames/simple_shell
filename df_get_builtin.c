#include "main.h"

/**
 * get_builtin - the builtin that parse the command in the arg
 * @commd: the command
 * Return: the function pointer of the builtin command
 */
int (*get_builtin(char *commd))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, commd) == 0)
			break;
	}

	return (builtin[i].f);
}
