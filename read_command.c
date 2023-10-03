#include "main.h"

/**
* read_command - Obtain command and parameters from user input
* @cmd: Buffer to hold the command from user input
* @par: An array of pointers to the parameters from user input
*/

void read_command(char cmd[], char *par[])
{
	char buffer[1024]; /* Buffer to contain parameters */
	int argc = 0; /* Argument index */
	int idx1 = 0, idx2 = 0; /* For looping */
	char *argv[100]; /* Parsed command and parameters */
	char *token; /* For tokenization of user input */
	int ret_value;

	/* Read line to extract user input */
	for (;;)
	{
		ret_value = fgetc(stdin); /* Obtain user input */
		buffer[argc] = (char)ret_value;
		argc++;

		if (ret_value == '\n')
			break;
	}

	if (argc == 1) /* Means if user does not input anything but hits enter */
		return;

	token = strtok(buffer, " \n"); /* Tokenize user input */

	/* Parse the line into words */
	while (token != NULL)
	{
		argv[idx1] = strdup(token);
		token = strtok(NULL, " \n");
		idx1++;
	}

	strcpy(cmd, argv[0]); /* First word from user input is a command */

	/* Subsequent words are parameters */
	while (idx2 < idx1)
	{
		par[idx2] = argv[idx2];
		idx2++;
	}
	par[idx2] = NULL; /* Null terminate paramater list */
}
