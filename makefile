mmult: mmult.o matrixFunctions.o
	gcc -o mmult mmult.o matrixFunctions.o

mmult.o: mmult.c mmult.h matrixFunctions.h
	gcc -c mmult.c

matrixFunctions.o: matrixFunctions.c matrixFunctions.h mmult.h
	gcc -c matrixFunctions.c
