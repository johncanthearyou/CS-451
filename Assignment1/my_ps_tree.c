// Samantha Souder, John Stockton
// CS-451
// Dr. Kanchi
// Summer 2022

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>
#include "queueADT.h"

int mypstree(int pid) {
    // Guard non-existant process
    int pidExists = getpgid(pid) >= 0;
    if (!pidExists) {
        printf("ERROR! PID: %d does not exist. Program will exit.\n", pid);
        exit(3);
    }

    // Initialize queue with root pid
    queueType *queue = create();
    enqueue(pid, queue);

    getChildrenForPid(pid);
    return -1;
}

void getChildrenForPid(int pid) {
    char path[100];
    char proc[] = "proc/";
    char task[] = "task/";
    char children[] = "children\0";
    sprintf(
        path,
        "%s%d%s%d%s",
        proc,
        pid,
        task,
        pid,
        children
    );
    printf("%s", path);
    
    // fopen(childrenPath, 'r');
}

int main(int argc, char* argv[]) {
    int targetPid = atoi(argv[1]);
    mypstree(targetPid);
}