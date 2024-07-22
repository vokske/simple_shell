#include <stdio.h>

extern char **environ;

int main(int ac, char **av)
{
	for (int i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
	return 0;
}
