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
		read_command();
	}

	return(0);
}
