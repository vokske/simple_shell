#include "shell.h"

/**
 * main - Prompt for the shell
 *
 * Return: Always 0
 */
int main(void)
{
	while (1)
	{
		printf("$ ");
		_cmdline_with_args();
	}

	return(0);
}
