#include "main.h"
#include <stdlib.h>
/**
 * repl_exit -  exits the shell
 */

void repl_exit(int exit_status)
{
	exit(exit_status);
}

#include "main.h"

/**
 * shell_exit - handles the exit command
 * @userinput_cpy: array of arguments and commands
 */
void shell_exit(char **userinput_cpy)
{
    int exit_status = 0;

    if (userinput_cpy[1] != NULL)
        exit_status = atoi(userinput_cpy[1]);

    repl_exit(exit_status);
}
