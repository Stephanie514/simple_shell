#include "main.h"
/**
 * _strlen - function that returns the length of a string
 * @s: string to be checked
 *
 * Return: Length of the string
 */
int _strlen(const char *s)
{
	int length = 0;

	while (s[length] != '\0')
		length++;
	return (length);
}
