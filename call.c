#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <proc_sem.h>

int main(void) {
    assert(proc_sem_get_num() == -1); 
	proc_sem_init(1);
    int start_group = proc_sem_get_num();
	assert(start_group >= 0);

    {
		pid_t child = fork();

		if (child == 0) {
			assert(proc_sem_get_num() == start_group);
			sleep(3);
			assert(proc_sem_get_num() == start_group);
			exit(0);
		} else {
			assert(proc_sem_get_num() == start_group);
			assert(proc_sem_init(1) == 0);
			assert(proc_sem_get_num() > start_group);
			waitpid(-1, NULL, 0);
		}
    }

	int intermediate_group = proc_sem_get_num();

    pid_t child = fork();
    if (child == 0) {
        assert(proc_sem_get_num() == intermediate_group);
		assert(proc_sem_init(1) == 0);
        assert(proc_sem_get_num() > intermediate_group);
        sleep(3);
        exit(0);
    } else {
        sleep(1);
        assert(proc_sem_get_num() == intermediate_group);
        waitpid(-1, NULL, 0);

        assert(proc_sem_get_num() == intermediate_group);
    }
}

