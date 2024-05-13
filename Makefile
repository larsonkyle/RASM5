CC = g++
FLAGS = -std=c++14

all: main

main: readFile.o BubbleSortC.o BubbleSortA.o
	$(CC) $(FLAGS) -o main main.cpp file_operations/read_file/readFile.o sort_functions/assemblySort/BubbleSortA.o sort_functions/C_Sort/BubbleSortC.o

readFile.o: readFile.h readFile.cpp
	$(CC) -c -o file_operations/read_file/readFile.o file_operations/read_file/readFile.cpp

BubbleSortC.o: BubbleSortC.h BubbleSortC.cpp
	$(CC) -c -o sort_functions/C_Sort/BubbleSortC.o sort_functions/C_Sort/BubbleSortC.cpp

BubbleSortA.o: BubbleSortA.s
	as -g -o sort_functions/assemblySort/BubbleSortA.o sort_functions/assemblySort/BubbleSortA.cpp

clean:
	rm main *.o
