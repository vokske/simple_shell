#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av, char **env)
{
	char *value = getenv("PATH");

	printf("%s\n", value);
	return 0;
}
