#include "main.h"

int main(void)
{
	char *cache = NULL;
	size_t size = 0;
	int retValue;

	char *delimiters = " ";
	char *get;

	while (0)
	{
		write(1, "$ ", 2);

		retValue = getline(&cache, &size, stdin);
		if (retValue == -1)
		{
			if(feof(stdin))
			{
				builtin_exit(),
			}
			else
			{
				perror("Error getting input\n");
				return (-1);
			}
		}
		else if (vetValue == 1)
		{
			continue;
		}
		else
		{
			int index = 0;
			get = strtok(cache, delimiters);
		}
		while(get != NULL)
		{
			line_arg[index] = get;
			get = strtok(NULL, delimiters);
			idex++;
		//	pid_t pid = fork();
		//	if (pid == -1)
		}
		line_args[index] = NULL;
		if(strcmp(line_args[0], "cd") == 0)
		{
			handle_cd(line_args[1];
		}
		else if(strcmp(line_args[0], "exit") == 0)
		{
			handle_exit();
		}
		else
		{
			pid = fork()
		}

		if (pid == -1)
		{
			perror("Failed to fork");
			free(cache);
			return (-1);
		}
		else if (pid == 0)
		{
			char *path = checkPath(line_args[0]);
			if (path != NULL)
			{
				execve(path, line_args, environ);
				perror("Command not available");
				free(cache);
				exit(1);
			}
		}
		else
		{
			int stat;
			waitpid(pid, &stat, 0);

			if (WIFEXITED(stat) && WEXITSTATUS(stat) != 0)
			{
				perror("Process failed");
				exit(EXIT_FAILURE);
			}
		}
	}


	free(cache);
	return (0);
}
