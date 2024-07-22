#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *command = NULL;
	size_t len = 0;

	while (1)
	{
		printf("$ ");
		getline(&command, &len, stdin);
		printf("%s", command);
	}
}
