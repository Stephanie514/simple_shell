#include "main.h"
#define HIGHEST_EXTENT 256

/*shell_exit fx declaration*/
void shell_exit(char **userinput_cpy);

/**
 * repl_loop - main loop of the shell
 * @exit_status: exit status
 */
void repl_loop(int *exit_status)
{
	char disp[HIGHEST_EXTENT], *userinput_cpy[HIGHEST_EXTENT / 2 + 1];
	int disp_prompt = isatty(STDIN_FILENO);
	char *userinput = NULL;
	char before_char, *n;
	int incitation;

	while (1)
	{
		if (disp_prompt)
			write(STDOUT_FILENO, "#MySHELL$ ", 10);
		if (fgets(disp, HIGHEST_EXTENT, stdin) == NULL)
			break;
		incitation = 0;
		before_char = '\0';
		for (n = disp; *n != '\0'; ++n)
		{
			if (*n == '"' && before_char != '\\')
				incitation = !incitation;
			else if (*n == '#' && !incitation && before_char != '\\')
			{
				/*userinput = n;*/
				*n = '\0';
				break;
			}
			before_char = *n;
		}
		if (userinput != NULL)
			*userinput = '\0';
		
		disp[strcspn(disp, "\n")] = '\0';
		tokenize_input(disp, userinput_cpy);
		if (userinput_cpy[0] == NULL)
			continue;
		if (_strcmp(userinput_cpy[0], "exit") == 0)
		{
			shell_exit(userinput_cpy);
			return;
		}
		if (_strcmp(userinput_cpy[0], "env") == 0)
		{
			umgebung_builtin();
			continue;
		}
		*exit_status = execute_command(userinput_cpy);
	}
}
