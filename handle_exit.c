#include "main.h"

void handle_exit(void)
{
	const char exitingMessage[] = "\nExiting shell...\n";
	write(1, exitingMessage, sizeof(exitingMessage) - 1);
	exit(0);
}
