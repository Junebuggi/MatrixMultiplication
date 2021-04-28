#include "mmult.h"
#include "matrixFunctions.h"

/**
 * This is the main function of the program. It will allocate the shared memory
 * segment and make this accessible to the program. M and N are 4x4 matrices and
 * will be multiplied using 4 child processes (each process is responsible for
 * adding in one complete row into Q). The largest integer of each row will be
 * displayed, as well as the largest integer of Q. The time in microseconds for
 * all the child processes to complete is also displayed.
 *
 * Using the command line argument "mydata" uses my hardcoded test data
 * Using the command line option "-r" randomizes the matrices M and N
 *
 * Author: Emma Boulay
 *
 */
int main(int argc, char *argv[]){
    /*The shared memory segment is created with a call to shmget*/
    void *shared_memory = (void *)0;
    struct shared_matrices_t *matrices;
    struct timeval start, end;
    int shmid;

    srand((unsigned int) getpid());

    shmid = shmget((key_t) 1234, sizeof(struct shared_matrices_t), 0666 | IPC_CREAT);
    if (shmid == -1) {
        fprintf(stderr, "shmget failed\n");
        exit(EXIT_FAILURE);
    }
    /* Makes the shared memory accessible to the program. */
    shared_memory = shmat(shmid, (void *) 0, 0);
    if (shared_memory == (void *) -1) {
        fprintf(stderr, "shmat failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Memory attached at %X\n",shared_memory);

    matrices = (struct shared_matrices_t *) shared_memory;
    //If cmd lind args then use my test data
    if(argc > 1 && strcmp (argv[1], "mydata") == 0){
        int m[4][4] = {
                {1, 2, 3, 4},
                {5, 6,  7, 8},
                {9, 10, 11, 12},
                {13,  14,  15,  16}
        };
        int n[4][4] = {
                {16, 15, 14, 13},
                {12,  11,  10,  9},
                {8,  7,  6,  5},
                {4,  3,  2,  1}
        };
        copyMatrix(matrices->m ,m);
        copyMatrix(matrices->n ,n);

    } 
    //If -r option use a random matrix
    else if (argc > 1 && strcmp (argv[1], "-r") == 0) {
        randomMatrix(matrices->m);
        randomMatrix(matrices->n);
    } else{
        int m[4][4] = {
                {20, 20, 50, 40},
                {10, 6,  70, 8},
                {40, 3,  2,  10},
                {8,  7,  6,  5}
        };
        int n[4][4] = {
                {10, 30, 50, 70},
                {1,  3,  6,  8},
                {9,  5,  5,  7},
                {8,  6,  4,  5}
        };
        copyMatrix(matrices->m ,m);
        copyMatrix(matrices->n ,n);
    }

    int n_child = 4;
    /* Fork process about to start, record start time */
    gettimeofday(&start, NULL);

    for (int i = 0; i < N_PROCESS; i++) {
        pid_t pid = fork();
        switch (pid) {
            case -1:
                perror("fork failed");
                exit(EXIT_FAILURE);
            case 0:
                matrixMultiplication(matrices->m, matrices->n, matrices->q, i, matrices->Li);
                exit(0);
            default:
                break;
        }
    }
    while (n_child > 0) {
        wait(NULL);
        --n_child;
    }
    /* Child processes have all finished, record end time */
    gettimeofday(&end, NULL);

    printf("\nMatrix M is: \n");
    printMatrix(matrices->m);

    printf("\nMatrix N is: \n");
    printMatrix(matrices->n);

    printf("\nResulting matrix Q is: \n");
    printMatrix(matrices->q);

    printf("\n");
    printLi(matrices->Li, 4);

    printf("\nThe largest integer in Q is: %d\n", getLargestInt(matrices->Li, 4));

    printf("\nElapsed Time For Child Process to Complete: %ld micro sec\n\n",
           ((end.tv_sec * MICRO_SEC_IN_SEC + end.tv_usec) - (start.tv_sec * MICRO_SEC_IN_SEC + start.tv_usec)));

    if (shmdt(shared_memory) == -1) {
        fprintf(stderr, "shmdt failed\n");
        exit(EXIT_FAILURE);
    }
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        fprintf(stderr, "shmctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }

    return 0;


}
