#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	int status;

	//create the arguments for execve
	char *command[] = { "ls -l /tmp", NULL };

	//loop to create 5 child processes
	for (int i = 0; i < 5; i++)
	{
		//create a new child process
		pid = fork();

		//check for fork error
		if (pid < 0)
		{
			perror("pid");
			exit(EXIT_FAILURE);
		}

		//operation in the child process
		if (pid == 0)
		{
			//execute the `ls -l /tmp` command & check return value
			if (execve("/bin/ls", command, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}

		//operation in parent process
		else
		{
			//wait for child process to terminate
			if (wait(&status) == -1)
			{
				perror("wait");
				exit(EXIT_FAILURE);
			}
			//check if child process exited normally
			if (WIFEXITED(status))
			{
				printf("Child process %d exited with status %d\n\n", pid, WEXITSTATUS(status));
			}
			else
			{
				printf("Child process %d did not exit normally\n", pid);
			}
		}
	}
	return (0);
}
