#include "main.h"

void handle_cd(char, *args)
{
	if (args == NULL)
	{
		char *home = getenv("HOME");
		if (home == NULL)
		{
			perror("cd: HOME environment variables error\n");
		}
		else
		{
			if(chdir(home) != 0)
			{
				perror("Could not change directory");
			}
		}
	}
	else
	{
		if (chdir(args) != 0)
		{
			perror("Could not change directory");
		}
	}
}

