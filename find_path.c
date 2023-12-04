#include "main.h"
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define HIGHEST_EXTENT 4096
/**
  * get_path - Find the full path of a command in the system PATH
  * @cmd: The command to locate in the system PATH
  *
  * Return: On success, returns the full path of the command.
  *         If the command is not found, returns NULL.
  */
char *get_path(char *cmd)
{
	char *fileloc = getenv("PATH");
	char *fileloc_tok = _strtok(fileloc, ":");
	char *file_address = malloc(HIGHEST_EXTENT * sizeof(char));
	int dir_size;
	char *full_fileloc;
	struct stat buf;

	while (fileloc_tok != NULL)
	{
	dir_size = _strlen(fileloc_tok) + _strlen(cmd) + 2;
	full_fileloc = malloc(dir_size * sizeof(char));
	sprintf(full_fileloc, "%s/%s", fileloc_tok, cmd);

	if (stat(full_fileloc, &buf) == 0 && S_ISREG(buf.st_mode)
			&& (buf.st_mode & S_IXUSR))
	{
	free(file_address);
	return (full_fileloc);
	}

	free(full_fileloc);
	fileloc_tok = _strtok(NULL, ":");
	}

	free(file_address);
	return (NULL);
}
