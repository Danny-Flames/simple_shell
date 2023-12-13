#include "main.h"

/**
 * _strcat - this concatenate two strings
 * @dest: char pointer the dest of the copied str
 * @strPtr: const char pointer the source of str
 * Return: the destination
 */
char *_strcat(char *dest, const char *strPtr)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; strPtr[j] != '\0'; j++)
	{
		dest[i] = strPtr[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}
/**
 * *_strcpy - Copies the string pointed to by strPtr.
 * @dest: Type char pointer the dest of the copied str
 * @strPtr: Type char pointer the source of str
 * Return: the dest.
 */
char *_strcpy(char *dest, char *strPtr)
{

	size_t a;

	for (a = 0; strPtr[a] != '\0'; a++)
	{
		dest[a] = strPtr[a];
	}
	dest[a] = '\0';

	return (dest);
}
/**
 * _strcmp - Function that compares two strings.
 * @s1: type str compared
 * @s2: type str compared
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}
/**
 * _strchr - locates a character in a string,
 * @strPtr: string.
 * @c: character.
 * Return: the pointer to the first occurrence of the character c.
 */
char *_strchr(char *strPtr, char c)
{
	unsigned int i = 0;

	for (; *(strPtr + i) != '\0'; i++)
		if (*(strPtr + i) == c)
			return (strPtr + i);
	if (*(strPtr + i) == c)
		return (strPtr + i);
	return ('\0');
}
/**
 * _strspn - gets the length of a prefix substring.
 * @strPtr: initial segment.
 * @accept: accepted bytes.
 * Return: the number of accepted bytes.
 */
int _strspn(char *strPtr, char *accept)
{
	int i, j, bool;

	for (i = 0; *(strPtr + i) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(strPtr + i) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (i);
}
