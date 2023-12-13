
#include "main.h"

/**
 * rev_string - this reverses a string.
 * @inputed_str: input string.
 * Return: this has no return.
 */
void rev_string(char *inputed_str)
{
	int count = 0, i, j;
	char *str, temp;

	while (count >= 0)
	{
		if (inputed_str[count] == '\0')
			break;
		count++;
	}
	str = inputed_str;

	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}
