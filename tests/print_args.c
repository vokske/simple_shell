#include <stdio.h>
#include <unistd.h>

/**
 * main - Print command line arguments
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	int count;

	for (count = 1; av[count] != NULL; count++)
	{
		printf("%s\n", av[count]);
	}
	return (0);
}
