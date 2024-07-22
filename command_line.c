#include "shell.h"


int main(void)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t line_read;
	int wstatus;
	pid_t pid;
	char *args[2];

	while (1)
	{
		printf("$ ");

		line_read = getline(&command, &len, stdin);

		if (line_read == -1)
		{
			break;
		}

		if (command[line_read - 1] == '\n')
		{
			command[line_read - 1] = '\0';
		}

		args[0] = command;
		args[1] = NULL;

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{

			if (execve(command, args, environ) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (waitpid(pid, &wstatus, 0) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
		}
	}
	free(command);
	return (0);
}
