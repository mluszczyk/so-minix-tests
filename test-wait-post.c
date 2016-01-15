#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <proc_sem.h>

int main() {

	proc_sem_init(1);
	proc_sem_post(0);

	printf("Forking. One of processes should print after one second.\n");
	pid_t child = fork();

	assert(child >= 0);
	proc_sem_wait(0);
	printf("I'm here\n");
	sleep(1);
	proc_sem_post(0);

	if (child != 0) {
		waitpid(-1, NULL, 0);
	}

	return 0;
}
