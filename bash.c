#include <stdlib.h>
#include <unistd.h>
#include <proc_sem.h>
#include <assert.h>

int main() {
	proc_sem_init(1);

	execl("/usr/pkg/bin/bash", "bash", NULL);
	assert(0);
    return 0;
}
