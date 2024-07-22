#include <unistd.h>
#include <stdio.h>

/**
 * main - PID
 *
 * Return: Always 0
 */
int main(void)
{
	pid_t myppid;

	myppid = getppid();
	printf("%u\n", myppid);
	return (0);
}
