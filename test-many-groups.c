#include <assert.h>
#include <proc_sem.h>

int main() {
	for (int i = 0; i < 500; ++i) {
		int ret = proc_sem_init(1);
		assert(ret == 0);
		proc_sem_post(0);
		proc_sem_wait(0);
	}
}
