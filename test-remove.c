#include <proc_sem.h>
#include <unistd.h>
#include <assert.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

pid_t spawn_waiting(int num) {
	pid_t child = fork();
	assert(child >= 0);

	if (child == 0) {
		proc_sem_wait(0);
		printf("%d woken up!\n", num);
		exit(0);
	}

	// parent
	assert(child > 0);
	return child;
}

int main() {
	proc_sem_init(1);
	
	pid_t pids[10];
	for (int i = 0; i < 10; ++i) {
		pids[i] = spawn_waiting(i);
	}

	for (int i = 0; i < 10; i += 2) {
		kill(pids[i], SIGKILL);
	}

	for (int i = 1; i < 10; i += 2) {
		proc_sem_post(0);
	}

	for (int i = 0; i < 10; ++i) {
		pid_t res = waitpid(pids[i], NULL, 0);
		assert(res == pids[i]);
	}
}
