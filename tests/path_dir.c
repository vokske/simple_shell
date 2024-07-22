#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_path_dirs()
{
	char *path = getenv("PATH");
	if (path == NULL)
		return;

	char *dir = strtok(path, ":");

	while (dir != NULL)
	{
		printf("%s\n", dir);
		dir = strtok(NULL, ":");
	}
}

int main()
{
	print_path_dirs();
	return 0;
}
