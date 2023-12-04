#include "main.h"

/**
 * *_strcpy - a function that copies the string pointed to by src
 * to the buffer pointed to by dest.
 * @dest: char type string
 * @src: char type string
 * Return: Pointer to 'dest'
 */

char *_strcpy(char *dest, char *src)
{
int e = -1;
do {
e++;
dest[e] = src[e];
} while (src[e] != '\0');
return (dest);
}
