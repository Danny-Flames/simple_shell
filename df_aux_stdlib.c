#include "main.h"

/**
 * get_len - Get the length of a number.
 * @num: type int number.
 * Return: Lenght of a number.
 */
int get_len(int num)
{
	unsigned int n1;
	int lenght = 1;

	if (num < 0)
	{
		lenght++;
		n1 = num * -1;
	}
	else
	{
		n1 = num;
	}
	while (n1 > 9)
	{
		lenght++;
		n1 = n1 / 10;
	}

	return (lenght);
}
/**
 * aux_itoa - this function converts int to string.
 * @num: type int number
 * Return: String.
 */
char *aux_itoa(int num)
{
	unsigned int n1;
	int lenght = get_len(num);
	char *buffer;

	buffer = malloc(sizeof(char) * (lenght + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + lenght) = '\0';

	if (num < 0)
	{
		n1 = num * -1;
		buffer[0] = '-';
	}
	else
	{
		n1 = num;
	}

	lenght--;
	do {
		*(buffer + lenght) = (n1 % 10) + '0';
		n1 = n1 / 10;
		lenght--;
	}
	while (n1 > 0)
		;
	return (buffer);
}

/**
 * _atoi - this is to convert a string to an integer.
 * @s: input string.
 * Return: integer.
 */
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
