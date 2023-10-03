#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid, ppid;

	pid = getpid();
	ppid = getppid();

	printf("Sum of 25 + 50 = %d\n", 75);
	printf("PPID = %u\nPID = %u\n", ppid, pid);

	return (0);
}
