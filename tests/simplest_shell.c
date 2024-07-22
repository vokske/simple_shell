#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
	while (1)
	{
		//prompt the user for input
		printf("$ ");

		//create a buffer/array to store the command
        	char command[1024];

		//read command & handle EOF (Ctrl+D)
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			break;
		}

		//remove the newline character
		size_t len = strlen(command);

		if (len > 0 && command[len - 1] == '\n')
		{
			command[len - 1] = '\0';
		}

		//check for exit condition
		if (strcmp(command, "exit") == 0)
		{
			break;
		}

		//fork a new process
		pid_t pid = fork();

		//check for fork error
		if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		//Execute command in child process
		if (pid == 0)
		{
			char *args[] = {command, NULL};
			if (execve(command, args, NULL) == -1)
			{
				perror("execve");
			}
		}
		//wait for child to terminate in parent process
		else
		{
			int wstatus;
			if (wait(&wstatus) == -1)
			{
				perror("wait");
				exit(EXIT_FAILURE);
			}
		}
	}
	return (0);
}
