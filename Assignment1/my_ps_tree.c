// Samantha Souder, John Stockton
// CS-451
// Dr. Kanchi
// Summer 2022

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int mypstree(int pid) {
    // Guard non-existant process
    int pidExists = getpgid(pid) >= 0;
    if (!pidExists) {
        printf("ERROR! PID: %d does not exist. Program will exit.\n", pid);
        exit(3);
    }


    return -1;
}

int main() {
    printf("%d", mypstree(69));
}