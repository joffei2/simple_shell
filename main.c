#include "main.h"

int main(void)
{
	char *cache = NULL;
	size_t size = 0;
	int retValue;

	char *delimiters = " ";
	char *get;

	write(1, "$ ", 2);

	retValue = getline(&cache, &size, stdin);
	if (retValue == -1)
	{
		perror("Error getting input");
		return (-1);
	}
	else 
	{
		get = strtok(cache, delimiters);
	}
	while(get != NULL)
	{
		pid_t pid = fork();
		if (pid == -1)
		{
			perror("Failed to fork");
			return (-1);
		}
		else if (pid == 0)
		{
			char *path = checkPath(get);
			if (path == NULL)
			{
				perror("Command not available");
				exit(1);
			}
			execve(path, &get, __environ);
			if (execve(path, &get, __environ) == -1)
			{
				perror("execve Execution failed");
				exit(EXIT_FAILURE);
			}
		}
	}
	return (0);
}
