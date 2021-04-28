#ifndef MMULT_H
#define MMULT_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/shm.h>
#include <sys/time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N_PROCESS 4
#define ROW 4
#define COL 4
#define MICRO_SEC_IN_SEC 1000000

/**
 * This defines the shared memory to be used by all
 * the process to store the results of the multiplication
 *
 * Author: Emma Boulay
 */
struct shared_matrices_t {
    int m[ROW][COL];
    int n[ROW][COL];
    int q[ROW][COL]; //The resultant matrix
    int Li[ROW]; //An array of each row's largest int
};

#endif
