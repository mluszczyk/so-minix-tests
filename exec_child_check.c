#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "sem.h"

int main() {
    int group = getsemgroup();
    assert(getsemgroup() == 117);
    printf("%d\n", group);
}

