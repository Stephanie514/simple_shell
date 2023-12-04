#include "main.h"
/**
 * main - this is THE entry point of
 * OUR shell program Umgebung
 *
 * Return: 0
 */

int main(void)
{
	int exit_status = 0;

	repl_loop(&exit_status);

	return (exit_status);
}
