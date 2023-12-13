#include "main.h"

/**
 * _strdup - this duplicates a str in the heap memory.
 * @strPtr: Type char pointer str
 * Return: to hold the duplicated str
 */
char *_strdup(const char *strPtr)
{
	char *new;
	size_t len;

	len = _strlen(strPtr);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, strPtr, len + 1);
	return (new);
}

/**
 * _strlen - This returns the lenght of a string.
 * @strPtr: Type char pointer
 * Return: Always 0.
 */
int _strlen(const char *strPtr)
{
	int len;

	for (len = 0; strPtr[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_chars - to compare chars of strings
 * @str: the input string.
 * @delim: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * _strtok - this splits a string by some delimiter.
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: string splited.
 */
char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str; /*Store first address*/
		i = _strlen(str);
		str_end = &str[i]; /*Store last address*/
	}
	str_start = splitted;
	if (str_start == str_end) /*Reaching the end*/
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		/*Breaking loop finding the next token*/
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - this will define if string passed is a number
 *
 * @strPtr: input string
 * Return: 1 if string is a number else 0 in other case.
 */
int _isdigit(const char *strPtr)
{
	unsigned int i;

	for (i = 0; strPtr[i]; i++)
	{
		if (strPtr[i] < 48 || strPtr[i] > 57)
			return (0);
	}
	return (1);
}
