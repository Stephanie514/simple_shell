#include "main.h"

/**
 * _strcat - function appends the src string to the dest string
 * overwriting the terminating null byte (\0) at
 * the end of dest, and then adds a terminating null byte.
 * @dest: destination string pointer
 * @src: source string pointer
 * Return: pointer to destination string
 */

char *_strcat(char *dest, char *src)
{
int stringLength, a;
stringLength = 0;
while (dest[stringLength] != '\0')
{
stringLength++;
}
for (a = 0; src[a] != '\0'; a++, stringLength++)
{
dest[stringLength] = src[a];
}
dest[stringLength] = '\0';
return (dest);
}
