#include <assert.h>
#include <proc_sem.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	for (int i = 0; i < 500; ++i) {
		pid_t child = fork();
		assert(child >= 0);
		if (child == 0) {
			int ret = proc_sem_init(1);
			assert(ret == 0);
			proc_sem_post(0);
			proc_sem_wait(0);
			exit(0);
		} else {
			assert(waitpid(child, NULL, 0) == child);
		}
	}
}
