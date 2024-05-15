#include <iostream>
#include <string>
#include <limits>
#include <ctime>

#include "file_operations/read_file/readFile.h"
#include "sort_functions/C_Sort/BubbleSortC.h"
#include "sort_functions/C_Sort/InsertionSortC.h"

extern "C" void InsertionSortA(int arr[], int length);
extern "C" void BubbleSortA(int arr[], int length);

void   printMenu(double elemCount, double cTime, double aTime, double cITime, double aITime);
double timedBubbleSortA(int arr[], int length);
double timedBubbleSortC(int arr[], int length);
double timedInsertionSortC(int arr[], int length);
double timedInsertionSortA(int arr[], int length);

#define ARRAY_SIZE 200000

int main(){
	int array[ARRAY_SIZE];			// statically declare array
	std::string filename = "input.txt";	// set filename
	
	//Console Menu Counters
	int fileElementCount = 0;		// # of items read in 
	double cTime  = 0;			// speed of c bubblesort
	double aTime  = 0;			// speed of assembly bubblesort
	double cITime = 0;			// speed of c insertion sort
	double aITime = 0;			// speed of assembly insertion sort

	int userInput;
	do{
		std::system("clear");						// system clear screen

		printMenu(fileElementCount, cTime, aTime, cITime, aITime);	// print screen with menu counters
		std::cin >> userInput;

		//Handle user Input
		switch(userInput){
			case 1:
				fileElementCount = readFile(array, ARRAY_SIZE, filename);
				break;
			case 2:
				cTime = timedBubbleSortC(array, ARRAY_SIZE);
				break;

			case 3: 
				aTime = timedBubbleSortA(array, ARRAY_SIZE);
				break;

			case 4: 
				cITime = timedInsertionSortC(array, ARRAY_SIZE);
				break;

			case 5: 
				aITime = timedInsertionSortA(array, ARRAY_SIZE);
				break;

			case 6: 
				std::cout << "\nExiting Program...\n";
				break;

			default: break;
		}
		
	}while(userInput != 6);

	return 0;
}

void printMenu(double elemCount, double cTime, double aTime, double cITime, double aITime){
	std::cout << "\nContributers: Kyle Larson\nProject     : RASM5\nClass       : CS3B\nProfessor   : Dr.Barnett\nDue Date    : 5/16/2024\n\n\n\n\n";

	std::cout << "------------------------------------------------\n";
	std::cout << "               RASM5 C vs Assembly\n";
	std::cout << "              File Element Count: " << elemCount << "\n";
	std::cout << "------------------------------------------------\n";
	std::cout << "C        Bubblesort Time   : " << cTime << " secs\n";
	std::cout << "Assembly Bubblesort Time   : " << aTime << " secs\n\n";
	std::cout << "C        Insertionsort Time: " << cITime << " secs\n";
	std::cout << "Assembly Insertionsort Time: " << aITime << " secs\n";
	std::cout << "------------------------------------------------\n";
	std::cout << "  <1> Load input file (integers)\n  <2> Sort using C bubbleSort algorithm\n  <3> Sort using Assembly bubbleSort algorithm\n  <4> Sort using C insertionSort algorithm\n  <5> Sort using Assembly insertionSort algorithm\n  <6> Quit\n";
}

double timedBubbleSortA(int arr[], int length){
	std::clock_t startTime = clock();

	BubbleSortA(arr, length);

	double elapsedTime = static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC;

	return elapsedTime;

}

double timedBubbleSortC(int arr[], int length){
	std::clock_t startTime = clock();

	BubbleSortC(arr, length);
	double elapsedTime = static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC;
	
	return elapsedTime;
}

double timedInsertionSortC(int arr[], int length){
	std::clock_t startTime = clock();

	InsertionSortC(arr, length);
	double elapsedTime = static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC;
	
	return elapsedTime;
}

double timedInsertionSortA(int arr[], int length){
	std::clock_t startTime = clock();

	InsertionSortA(arr, length);
	double elapsedTime = static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC;
	
	return elapsedTime;
}
