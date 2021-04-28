Assignment 1: Shared Memory and Matrix Multiplication
Name: Emma Boulay
Student Number: 101073617

Set-Up Instructions:
1. Extract the archived files in 101073617_Assignment1.tar.gz
	$ tar -xvzf 101073617_Assignment1.tar.gz
2. Run the makefile to compile:
	$ make
3. Run the program:
	$ ./mmult
4. To run the program with my test data:
	$ ./mmult mydata
5. To run the program with random matrices use the -r option:
	$ ./mmult -r

/********** Discussion of Test Results ***********/
The output for both my test data and the given test data is given below.
From running with both data sets multiple times the average time it takes for
the child process to compute the matrix multiplication and complete is ~500 ms.
Running the computations for each row concurrently allows for faster computations.

/*********** Output for the given test data ***********/
Memory attached at F3ED000
Child Process is working on row: 1
Child Process is working on row: 2
Child Process is working on row: 3
Child Process is working on row: 4

Matrix M is: 
20 20 50 40 
10 6 70 8 
40 3 2 10 
8 7 6 5 

Matrix N is: 
10 30 50 70 
1 3 6 8 
9 5 5 7 
8 6 4 5 

Resulting matrix Q is: 
990 1150 1530 2110 
800 716 918 1278 
501 1279 2068 2888 
181 321 492 683 

The largest integer of row 1 is: 2110
The largest integer of row 2 is: 1278
The largest integer of row 3 is: 2888
The largest integer of row 4 is: 683

The largest integer in Q is: 2888

Elapsed Time For Child Processes to Complete: 524 micro sec

/********** Output for my test data ***********/
Memory attached at C820000
Child Process is working on row: 1
Child Process is working on row: 2
Child Process is working on row: 3
Child Process is working on row: 4

Matrix M is: 
1 2 3 4 
5 6 7 8 
9 10 11 12 
13 14 15 16 

Matrix N is: 
16 15 14 13 
12 11 10 9 
8 7 6 5 
4 3 2 1 

Resulting matrix Q is: 
80 70 60 50 
240 214 188 162 
400 358 316 274 
560 502 444 386 

The largest integer of row 1 is: 80
The largest integer of row 2 is: 240
The largest integer of row 3 is: 400
The largest integer of row 4 is: 560

The largest integer in Q is: 560

Elapsed Time For Child Processes to Complete: 487 micro sec

/********** Output for my random test data ***********/
Memory attached at C7A4F000
Child Process is working on row: 1
Child Process is working on row: 2
Child Process is working on row: 3
Child Process is working on row: 4

Matrix M is: 
12 54 12 65 
8 51 47 27 
7 93 86 89 
1 59 13 15 

Matrix N is: 
19 42 73 52 
94 80 26 94 
87 11 20 3 
83 85 94 92 

Resulting matrix Q is: 
11743 10481 8630 11716 
11276 7228 5388 7835 
23744 16245 13015 17552 
7941 6180 3277 7017 

The largest integer of row 1 is: 11743
The largest integer of row 2 is: 11276
The largest integer of row 3 is: 23744
The largest integer of row 4 is: 7941

The largest integer in Q is: 23744

Elapsed Time For Child Processes to Complete: 564 micro sec
