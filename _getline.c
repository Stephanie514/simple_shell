#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUF_SZ 1024

/**
 * _getline - function that reads input from the user
 * @lineptr: double pointer to store userinput
 * @n: a malloc_allocated buffer size(adjusts acc to input size)
 * @stream: points to stdin
 * Return: characters read, including '\0'
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char container[BUF_SZ];
	static size_t buf_index;
	size_t line_index = 0;
	char v;

	buf_index = 0;
	if (*lineptr == NULL)
		*lineptr = malloc(*n);
	if (*lineptr == NULL)
		return (-1);
	while (1)
	{
	if (buf_index == 0)
	{
		size_t read_input = fread(container, 1, BUF_SZ, stream);
	if (read_input == 0)
		return (-1);
	}
	v = container[buf_index++];
	if (v == '\n' || buf_index == BUF_SZ)
	{
	(*lineptr)[line_index++] = '\0';
		*n = line_index;
		buf_index = 0;
		return (line_index);
	}
	(*lineptr)[line_index++] = v;
	if (line_index >= *n)
	{
	*n += BUF_SZ;
	*lineptr = realloc(*lineptr, *n);
		if (*lineptr == NULL)
			return (-1);
	}
	}
}
