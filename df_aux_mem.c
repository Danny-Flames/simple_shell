#include "main.h"

/**
 * _memcpy - this copies information between void pointers.
 * @newptr: the destination pointer.
 * @incoming_ptr: the source pointer.
 * @size: size of the new pointer.
 *
 * Return: has no return.
 */
void _memcpy(void *newptr, const void *incoming_ptr, unsigned int size)
{
	char *char_ptr = (char *)incoming_ptr;
	char *char_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
}

/**
 * _realloc - re-allocates a memory block.
 * @incoming_ptr: reps the pointer to the memory previously allocated.
 * @old_size: size, in bytes, of the allocated space of incoming_ptr.
 * @new_size: new size, in bytes, of the new memory block.
 *
 * Return: incoming_ptr.
 * if new_size == old_size, returns incoming_ptr without changes.
 * if malloc fails, returns NULL.
 */
void *_realloc(void *incoming_ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (incoming_ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(incoming_ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (incoming_ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, incoming_ptr, new_size);
	else
		_memcpy(newptr, incoming_ptr, old_size);

	free(incoming_ptr);
	return (newptr);
}

/**
 * _reallocdp - reallocates a memory block of a double pointer.
 * @incoming_ptr: double pointer to the memory previously allocated.
 * @old_size: size, in bytes, of the allocated space of incoming_ptr.
 * @new_size: new size, in bytes, of the new memory block.
 *
 * Return: incoming_ptr.
 * if new_size == old_size, it returns incoming_ptr without changes.
 * if malloc fails, returns NULL.
 */
char **_reallocdp(char **incoming_ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int i;

	if (incoming_ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (incoming_ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		newptr[i] = incoming_ptr[i];

	free(incoming_ptr);

	return (newptr);
}
