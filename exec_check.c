#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/wait.h>
#include "sem.h"

int main() {
    setsemgroup(117);
    pid_t child = fork();

    if (child == 0) {
        assert(getsemgroup() == 117);
        execl("./exec_child_check", "a", NULL);
        assert(0);
    } else {
        int stat_loc;
        waitpid(child, &stat_loc, 0);
    }
    return 0;
}
