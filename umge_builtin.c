#include "main.h"

/**
 * umgebung_builtin - handles env variables
 *
 */

void umgebung_builtin(void)
{
	int y = 0;

	while (environ[y] != NULL)
	{
		write(STDOUT_FILENO, environ[y], strlen(environ[y]));
		write(STDOUT_FILENO, "\n", 1);
		y++;
	}
}
