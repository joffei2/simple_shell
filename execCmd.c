#include "main.h"

/**
 * arg - Handles the execution of the commands
 * @argv: Argument vector and it get the commands
 *
 * Return: Always 0 (Success)
 */

void arg(char **argv)
{
	char *command = NULL;
	char *actualCmd = NULL;

	if (argv)
	{
		command = argv[0];
		actualCmd = getPath(command);

		if (execve(actualCmd, argv, NULL) == -1)
		{
			perror("Error");
		}
	}
}
