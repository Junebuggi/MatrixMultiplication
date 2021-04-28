/*
 * The matrixFunctions source file contains all of the functions
 * used by the main program for Assignment 1.
 *
 * Author: Emma Boulay
 * Student Number: 101073617
 */
#include "mmult.h"
#include "matrixFunctions.h"

/**
 * This function is used by the child processes to add the result of row rowNum
 * to the matrix Q.
 *
 * @param m The first matrix multiplier
 * @param n The second matrix multipler
 * @param q The matrix store the product of m x n
 * @param rowNum The row to be worked on
 * @param Li An array to store the largest integer of the row
 */
void matrixMultiplication(int m[][COL], int n[][COL], int q[][COL], int rowNum, int Li[ROW]){
    printf("Child Process is working on row: %d\n", rowNum + 1);
    int sum = 0, i, j;

    for(i = 0; i < 4; i++, sum = 0){
        for(j = 0; j < 4; j++){
            sum += m[rowNum][j] * n[j][i];
        }
        //Store the sum in the matrix Q
        q[rowNum][i] = sum;
    }
    //Get the largest int of rowNum and store it in the Li array
    Li[rowNum] = getLargestInt(*(q+rowNum), 4);
}

/**
 * This function returns the largest integer of the array.
 *
 * @param arr The array of which you want to find its largerst integer
 * @param size The length of the array
 * @return The largest integer of arr
 */
int getLargestInt(int arr[ROW], int size){
    int max= arr[0];
    for(int i = 1; i < size; i++){
        if(max < arr[i])
            max = arr[i];
    }
    return max;
}

/**
 * This function prints a matrix of size ROW x COL
 *
 * @param mat The matrix to be printed
 */
void printMatrix(int mat[][ROW]){
    for(int row = 0; row < ROW;  row++){
        for(int col = 0; col < COL; col++){
            printf("%d ", mat[row][col]);
        }
        printf("\n");
    }
}

/**
 * This function prints out the Li array
 *
 * @param Li The Li array stored in shared memory
 */
void printLi(int Li[ROW], int size){
    for(int i = 0; i < size; i++){
        printf("The largest integer of row %d is: %d\n", i+1, Li[i]);
    }
}

/** 
 * This function randomizes each element of the matrix
 *
 * @param mat The 2D array to be randomized
 */
void randomMatrix(int mat[][COL]){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            mat[i][j] = (rand() % 99) + 1;
        }
    }
}

/**
 * This function copies each element of the src matrix into the
 * dest matrix
 * @param dest The matrix to hold the copy of src
 * @param src The matrix to be copied
 */
void copyMatrix(int dest[][COL], int src[][COL]){
     for(int i = 0; i < ROW; i++){
	 for(int j = 0; j < ROW; j++){
	     dest[i][j] = src[i][j];
	 }
     }
}
