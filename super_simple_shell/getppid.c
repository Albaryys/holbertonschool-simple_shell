#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t ppid;

	ppid = getppid();
	printf("Parent PID: %d\n", ppid);
	return (0);
}
