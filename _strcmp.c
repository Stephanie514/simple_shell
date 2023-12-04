#include "main.h"
/**
  * _strcmp - function that compares two strings.
  * @s1: pointer to first string
  * @s2: pointer to second string
  * Return: a value greater than 0 if string is greater
  * than the other, a value less than 0 if string is
  *
  * lesser than the other, and 0 if the strings are equal.
  */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
