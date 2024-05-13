#include "readFile.h"

void readFile(int arr[], int length, std::string filename){
	std::ifstream file(filename);
	int buffer;

	if(file.is_open()){
		int i = 0;
		while(!file.eof() && i < length){
			file >> buffer;
			arr[i++] = buffer;
		}
		std::cout << i << " Numbers Loaded into array.\n";
	}else
		std::cout << "ERROR: File did not open\n";

	if(file.is_open()) file.close();
}
