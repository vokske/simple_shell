#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **split_strtok(char *str)
{
	int count = 0;
	char *token;
	char **words;
	char *str_copy = strdup(str);
	token = strtok(str_copy, " ");

	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " ");
	}
	free(str_copy);

	words = malloc((count + 1) * sizeof(char *));
	count = 0;
	token = strtok(str, " ");

	while (token != NULL)
	{
		words[count++] = strdup(token);
		token = strtok(NULL, " ");
	}
	words[count] = NULL;

	return (words);
}

int main(int ac, char **av)
{
	char **words;
	int i;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s <string>\n", av[0]);
		return (1);
	}
	words = split_strtok(av[1]);
	for (i = 0; words[i] != NULL; i++)
	{
		printf("%s\n", words[i]);
		free(words[i]);
	}
	free(words);
}
