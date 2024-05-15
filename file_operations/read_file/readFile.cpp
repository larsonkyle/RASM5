#include "readFile.h"

int readFile(int arr[], int length, std::string filename){
	std::ifstream file(filename);

	int buffer;
	int i = 0;

	if(file.is_open()){
		while(!file.eof() && i < length){
			file >> buffer;
			arr[i++] = buffer;
		}
		//std::cout << i << " Numbers Loaded into array.\n";
	}else
		//std::cout << "ERROR: File did not open\n";

	if(file.is_open()) file.close();

	return i;
}
