#include "main.h"

/**
 * _strtrim - removes trailing whitespaces strings
 * @str: string to check
 *
 * Return: Output string
 */

char *_strtrim(char *str)
{
	char *mwisho;

	while (isspace((unsigned char)*str))
		str++;
	if (*str == '\0')
		return (str);
	mwisho = str + _strlen(str) - 1;
	while (mwisho > str && isspace((unsigned char)*mwisho))
		mwisho--;
	mwisho[1] = '\0';
	return (str);
}

/**
 * _strtok - tokenizes a string
 * @str: the string to be tokenized
 * @delim: the delimiter to use
 * Return: a pointer to the next token
 */
char *_strtok(char *str, const char *delim)
{
	static char *end;
	char *token;
	const char *delim_index;

	if (str)
		end = str;
	if (!*end)
		return (NULL);
	token = end;
	while (*end)
	{
		delim_index = delim;
		while (*delim_index)
		{
			if (*end == *delim_index)
			{
				*end = '\0';
				end++;
				if (*token)
					return (token);
				token = end;
				break;
			}
			delim_index++;
		}
		end++;
	}
	return (token);
}
