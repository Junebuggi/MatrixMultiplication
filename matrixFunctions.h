/**
 * This is the header file for matrixFunctions.c
 *
 * Author: Emma Boulay
 */

#ifndef MATRIXFUNCTIONS_H
#define MATRIXFUNCTIONS_H

void matrixMultiplication(int m[][COL], int n[][COL], int q[][COL], int rowNum, int Li[ROW]);
int getLargestInt(int arr[ROW], int size);
void printMatrix(int mat[][ROW]);
void printLi(int Li[ROW], int size);
void randomMatrix(int mat[][COL]);
void copyMatrix(int dest[][COL], int src[][COL]);

#endif
