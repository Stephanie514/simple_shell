#include "main.h"

#define PATH_MAX 4096

/**
* execute_command - a fx that executes the command with arguments
* @userinput_cpy: array of arguments and commands to execute
*
* Return: cmd's exit status
*/

int execute_command(char **userinput_cpy)
{
	char no_cmd[] = "Command doesn't exist.\n";
	char fork_fail[] = "Fork failed.\n";
	pid_t pid;
	int status, exit_status = 0;
	char *token;
	int y;
	char exit_code[10];
	char pid_str[20];

	pid = fork();
	if (pid == 0)
	{
		for (y =  0; userinput_cpy[y] != NULL; y++)
		{
			token = userinput_cpy[y];
			if (strcmp(token, "$?") == 0)
			{
				snprintf(exit_code, sizeof(exit_code), "%d", exit_status);
				userinput_cpy[y] = strdup(exit_code);
			}
			if (strcmp(token, "$$") == 0)
			{
				snprintf(pid_str, sizeof(pid_str), "%d", getpid());
				userinput_cpy[y] = strdup(pid_str);
			}
		}
		execvp(userinput_cpy[0], userinput_cpy);
		if (errno == ENOENT)
		{
			char err_alert_file[] = "./hsh: 0: Can't open ";

			write(STDERR_FILENO, err_alert_file,
					sizeof(err_alert_file) - 1);
			write(STDERR_FILENO, userinput_cpy[0],
					_strlen(userinput_cpy[0]));
			write(STDERR_FILENO, "\n", 1);
			exit(127);
		}
		else
		{
			write(STDERR_FILENO, no_cmd, sizeof(no_cmd));
			exit(127);
		}
	}
	else if (pid < 0)
	{
		write(STDERR_FILENO, fork_fail, sizeof(fork_fail));
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
	}
	if (_strcmp(userinput_cpy[0], "exit") == 0)
	{
		if (userinput_cpy[1] != NULL)
			repl_exit(atoi(userinput_cpy[1]));
		else
			repl_exit(0);
	}
	else if (_strcmp(userinput_cpy[0], "cd") == 0)
	{
		char *home_dir = _getenv("HOME");
		char *prev_dir = _getenv("PWD");
		char* target_dir;
		char cwd[PATH_MAX];

		if (userinput_cpy[1] != NULL)
		{
			if (strcmp(userinput_cpy[1], "-") == 0)
			{
				if (prev_dir != NULL)
				{
					target_dir = prev_dir;
				}
				else
				{
					printf("cd: No previous directory available.\n");
					return(1);
				}
			}
			else
			{
				target_dir = userinput_cpy[1];
			}
		}
		else
		{
		
			if (home_dir != NULL)
			{
				target_dir = home_dir;
			}
			else
			{
				printf("cd: No home directory found.\n");
				return (1);
			}
		}
		if (chdir(target_dir) != 0)
		{
			perror("cd");
			return (1);
		}
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			setenv("PWD", cwd, 1);
		}
		else
		{
			perror("getcwd");
		}
	}
	return (exit_status);
}
