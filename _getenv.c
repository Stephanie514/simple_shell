#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * _getenv - prints the environment value
 * @envv: envnmnt variable
 *
 * Return: pointer to value of environment variable
 * or NULL if not
 */
char *_getenv(const char *envv)
{
	unsigned int st;
	/*extern char **environ;*/
	size_t ln;

	if (envv == NULL)
		return (NULL);
	ln = strlen(envv);
	for (st = 0; environ[st] != NULL; st++)
	{
		if (strncmp(envv, environ[st], ln) == 0 && environ[st][ln] == '=')
		{
			return (&environ[st][ln + 1]);
		}
	}
	return (NULL);
}
