#include "shell.h"

/**
 * _cmdline_with_args - Executes commands with arguments
 *
 * Return: Always 0. 
 */
int _cmdline_with_args(void)
{
	char command[1024];
	char *args[256];
	int j, i = 0;
	pid_t pid;

	if (fgets(command, sizeof(command), stdin) == NULL)
	{
		perror("fgets");
		return (1);
	}

	command[strcspn(command, "\n")] = '\0';

	args[i] = strtok(command, " "); 
	while (args[i] != NULL)
	{
		i++;
		args[i] = strtok(NULL, " ");
	}
	
	for (j = 0; j < i; j++)
	{
		printf("Token[%d]: %s\n", j, args[j]);
	}

	pid = fork();

	if (pid < 0)
	{
		perror("fork");
		return (1);
	}
	else if (pid == 0)
	{
		execvp(args[0], args);
		perror("execvp");
		return (1);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
