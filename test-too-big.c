#include <proc_sem.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>

int main() {
	int err = proc_sem_init(1000000000);
	assert(err == ENOMEM);
}
