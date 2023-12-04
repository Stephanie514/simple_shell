#include "main.h"

/**
 * tokenize_input - splits given input into multiple words(tokens)
 * @userinput: given input to tokenize
 * @userinput_cpy: array of tokens (strings) obtained from the input
 *
 */

void tokenize_input(char *userinput, char **userinput_cpy)
{
	char *token;
	int y = 0;
	int space = 1;

	for (y = 0; userinput[y]; y++)
	{
		if (!isspace(userinput[y]) && userinput[y] != ';')
		{
			space = 0;
			break;
		}
	}
	if (space)
	{
		userinput_cpy[0] = NULL;
		return;
	}
	y = 0;
	token = _strtok(userinput, " ;");
	while (token)
	{
		userinput_cpy[y++] = token;
		token = _strtok(NULL, " ;");
	}
	userinput_cpy[y] = NULL;
	if (_strcmp(userinput_cpy[0], "exit") == 0)
	{
		if (userinput_cpy[1] != NULL)
			repl_exit(atoi(userinput_cpy[1]));
		else
			repl_exit(0);
	}
}
