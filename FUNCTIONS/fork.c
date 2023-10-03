#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid, ppid, t_ppid;

	printf("Before fork I did not exist\n");

	pid = fork();

	if (pid == -1)
	{
		perror("Unsucessful\n");
		return (1);
	}
	if (pid == 0)
	{
		sleep(30);
		printf("After fork I became the child\n");
	}
	else
	{
		ppid = getpid();
		t_ppid = getppid();

		printf("PPID: %u\n", ppid);
		printf("T_PPID: %u\n", t_ppid);
	}
	return (0);
}