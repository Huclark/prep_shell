#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	char *buffer = NULL, *buffer_cpy = NULL, *token = NULL, *delim = " \n", **argv = NULL;
	size_t buffer_size = 0;
	int argc = 0, i = 0;

	printf(":) ");

	if (getline(&buffer, &buffer_size, stdin) == -1)
		return (1);
	
	buffer_cpy = strdup(buffer);

	token = strtok(buffer, delim);
	while (token)
	{
		argc++;
		token = strtok(NULL, delim);
	}
	printf("%d\n", argc);

	token = strtok(buffer_cpy, delim);
	argv = malloc(sizeof(char *) * argc);
	while (token)
	{
		argv[i] = (token);
		token = strtok(NULL, delim);
		i++;
	}
	
	argv[i] = '\0';
	i = 0;

	while (argv[i])
	{
		printf("%s\n", argv[i++]);
	}

	/* while (i < argc)
	{
		free(argv[i]);
		i++;
	} */

	free(buffer);
	free(buffer_cpy);
	free(argv);

	return (0);
}
