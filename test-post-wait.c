#include <proc_sem.h>

int main() {
	proc_sem_init(1);
	proc_sem_post(0);
	proc_sem_post(0);
	proc_sem_wait(0);
	proc_sem_wait(0);
}
