#include "main.h"

/**
 * main - The main function for my shell
 * Return: 0 on success
*/

int main(void)
{
	char cmd[100], command[100], *parameters[20];
	char *envp[] = {(char *) "PATH=/bin", 0};

	while (1) /* repeat forever */
	{
		type_prompt(); /* display prompt on terminal screen */
		read_command(command, parameters); /* read input from user */

		if (fork() != 0) /* parent waits */
		{
			wait(NULL); /* waits for child */
		}
		else /*child process */
		{
			strcpy(cmd, "/bin/"); /* copy command from bin directory to cmd buffer */
			strcat(cmd, command); /* Concantenate */
			execve(cmd, parameters, envp); /* execute command */
		}
		if (strcmp(command, "exit") == 0)
			exit;
	}
	return (0);
}
