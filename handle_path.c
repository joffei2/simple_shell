#include "main.h"

char *checkPath(char *command)
{
	char *path = getenv("PATH");
	char *pathCopy = strdup(path);
	char *directory = strtok(pathCopy, ":");
	char commandPath[1000];

	while (directory != NULL)
	{
		strcpy(commandPath, directory);
		if (commandPath[strlen(commandPath)- 1] != '/')
		{
			strcat(commandPath, "/");
		}
		strcat(commandPath, command);
		if (access(commandPath, F_OK) == 0 && access(commandPath, X_OK) == 0)
		{
			free(pathCopy);
			return (strdup(commandPath));
			
		}
		directory = strtok(NULL, ":");
	}
free(pathCopy);
return (NULL);
}
