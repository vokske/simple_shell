#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

char *_getenv(const char *name)
{
	size_t name_len = strlen(name);

	for (char **env = environ; *env != NULL; env++)
	{
		if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return *env + name_len + 1;
		}
	}
	return NULL;
}

int main(int ac, char **av)
{
	char *value = _getenv("SHELL");

	if (value != NULL)
		printf("%s\n", value);
	else
		printf("Environment variable not found\n");

	return 0;
}
