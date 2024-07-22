#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - execute a program using execve function
 *
 * @argc: Argument counter
 * @argv: Argument vector
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	char *newargv[] = { NULL };
	char *newenviron[] = { NULL };

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file-to-exec>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	newargv[0] = argv[1];
	execve(argv[1], newargv, newenviron);
	perror("execve");
	exit(EXIT_FAILURE);
}
