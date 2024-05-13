CC = g++
FLAGS = -std=c++14

all: main

main: readFile.o BubbleSortC.o BubbleSortA.o
	$(CC) $(FLAGS) -o main main.cpp file_operations/read_file/readFile.o sort_functions/assemblySort/BubbleSortA.o sort_functions/C_Sort/BubbleSortC.o

readFile.o: file_operations/read_file/readFile.h file_operations/read_file/readFile.cpp
	$(CC) -c -o file_operations/read_file/readFile.o file_operations/read_file/readFile.cpp

BubbleSortC.o: sort_functions/C_Sort/BubbleSortC.h sort_functions/C_Sort/BubbleSortC.cpp
	$(CC) -c -o sort_functions/C_Sort/BubbleSortC.o sort_functions/C_Sort/BubbleSortC.cpp

BubbleSortA.o: sort_functions/assemblySort/BubbleSortA.s
	as -g -o sort_functions/assemblySort/BubbleSortA.o sort_functions/assemblySort/BubbleSortA.s

clean:
	rm main *.o
