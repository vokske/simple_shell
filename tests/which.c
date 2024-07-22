#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int ac, char **av)
{
	//check if command line args are provided
	if (ac < 2)
	{
		fprintf(stderr, "Usage: %s filename ...\n", av[0]);
		return 1;
	}

	//get the PATH environment variable
	char *path = getenv("PATH");
	if (path == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not found\n");
		return 1;
	}
	//copy PATH variable to a mutable string for modification later on
	char *path_copy = strdup(path);

	//tokenize the PATH variable using `:` as the delimiter
	//PATH contains directory names separated by a colon
	char *dir = strtok(path_copy, ":");

	//Loop through every directory in PATH
	while (dir != NULL)
	{
		//Loop through each filename provide as command line argument
		//snprintf constructs the full file path by concatenating
		//the directory and filename
		for (int i = 1; i < ac; i++)
		{
			char filepath[4096];
			snprintf(filepath, sizeof(filepath), "%s/%s", dir, av[i]);

			//check if the file exists in the directory using `stat`
                	struct stat buffer;
                	if (stat(filepath, &buffer) == 0)
                	{
                        	printf("%s found at %s\n", av[i], filepath);
                	}
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return 0;
}
