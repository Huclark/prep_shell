#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (void)
{
	pid_t pid;
	char *argv[] = {"/bin/ls", "-l", NULL};

	pid = fork();

	if (pid == -1)
	{
		perror("unsessful");
		return (1);
	}
	if (pid == 0)
	{
		int return_value = execve(argv[0], argv, NULL);
		
		if (return_value == -1)
		perror("Error\n");
	}
	else
	{
		wait(NULL);
		sleep(5);
		printf("Done with execve\n");
	}
	return (0);
}