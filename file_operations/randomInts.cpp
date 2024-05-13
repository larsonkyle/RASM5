#include <iostream>
#include <fstream>
#include <cstdlib>


int main(){
	const int     INT_FILE_SIZE = 200000;
	std::ofstream intFile;
	
	intFile.open("../input.txt");

	for(int i=0; i < INT_FILE_SIZE; i++){
		if(std::rand() % 2){
			intFile << std::rand() << std::endl;
		} else
			intFile << 0 - std::rand() << std::endl;
	}

	if(intFile.is_open()) intFile.close();
	return 0;
}
